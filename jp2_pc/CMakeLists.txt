cmake_minimum_required(VERSION 3.17)
project(JP2_PC)

# General build settings
set(CMAKE_SUPPRESS_REGENERATION TRUE)
set(CMAKE_MSVC_PARALLEL TRUE)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT trespass)

string(APPEND CMAKE_CXX_FLAGS " /MP /GF")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Linker flag required by self modifying assembly code in ScreenRenderDWI
string(APPEND CMAKE_EXE_LINKER_FLAGS " /SECTION:SelfMod,ERW")
string(APPEND CMAKE_SHARED_LINKER_FLAGS " /SECTION:SelfMod,ERW")

option(USE_TRESPASSER_DIRECTORY "Install to Trespasser installation directory" TRUE)

if(WIN32 AND USE_TRESPASSER_DIRECTORY)
    get_filename_component(TRESPASS_INSTALL_DIR
        "[HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\DreamWorks Interactive\\Trespasser;Installed Directory]"
        ABSOLUTE)
    if(NOT TRESPASS_INSTALL_DIR STREQUAL "/registry")
        set(CMAKE_INSTALL_PREFIX ${TRESPASS_INSTALL_DIR} CACHE PATH "Install prefix" FORCE)
        set(FOUND_TRESPASS_DIR TRUE)
    else()
        set(FOUND_TRESPASS_DIR FALSE)
    endif()
endif()

set(CMAKE_CONFIGURATION_TYPES Debug Release Final CACHE STRING INTERNAL FORCE)

# When cross compiling with mingw-w64, CMAKE_SYSTEM_NAME is "Windows" but
# WIN32 may not be set.  Ensure WIN32 is defined so Windows-specific code
# is enabled.
if(NOT WIN32 AND CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(WIN32 TRUE)
endif()

if(NOT WIN32 AND NOT CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(FATAL_ERROR
        "Non-Windows builds are unsupported. Use a mingw-w64 toolchain and set CMAKE_SYSTEM_NAME=Windows")
endif()

include(cmake/CMakeCommon.cmake)

include_directories(
    ${CMAKE_SOURCE_DIR}/../Lib           # for GblInc headers
    ${CMAKE_SOURCE_DIR}/Source/gblinc
    ${CMAKE_SOURCE_DIR}/Inc/DirectX      # legacy DirectX headers like dsound.h
)

if(NOT WIN32)
    # On non-Windows platforms the mingw-w64 headers provide Windows API stubs
    find_path(MINGW_INCLUDE_DIR windows.h
        PATHS /usr/x86_64-w64-mingw32/include /usr/i686-w64-mingw32/include
        /usr/share/mingw-w64/include
    )
    if(MINGW_INCLUDE_DIR)
        message(STATUS "Using mingw headers from ${MINGW_INCLUDE_DIR}")
        include_directories(SYSTEM ${MINGW_INCLUDE_DIR})
    else()
        message(WARNING "windows.h not found; build may fail")
    endif()
endif()

# Optional features
option(ENABLE_OCULUS_QUEST_SUPPORT "Build with Oculus Quest VR support" OFF)
option(ENABLE_MODERN_ENV_RENDER "Enable Modern OpenGL Cubemap Environment Renderer" OFF)
option(USE_SDL_CONTROLLER "Enable SDL2 game controller input" OFF)

if(ENABLE_OCULUS_QUEST_SUPPORT)
    add_subdirectory(cmake/VR)
endif()

if(ANDROID)
    add_subdirectory(${CMAKE_SOURCE_DIR}/../android ${CMAKE_BINARY_DIR}/android)
endif()

if(ENABLE_MODERN_ENV_RENDER)
    message(STATUS "Modern environment renderer enabled")
else()
    message(STATUS "Modern Env Render is explicitly disabled on desktop (no OpenGL).")
endif()

# Project subdirectories
add_subdirectory(cmake/AI)
add_subdirectory(cmake/AITest)
add_subdirectory(cmake/Audio)
add_subdirectory(cmake/AudioTest)
add_subdirectory(cmake/Bugs)
add_subdirectory(cmake/BumpBuild)
add_subdirectory(cmake/BumpTest)
add_subdirectory(cmake/CollisionEditor)
add_subdirectory(cmake/ColourTest)
add_subdirectory(cmake/EntityDBase)
add_subdirectory(cmake/Examples)
add_subdirectory(cmake/FastBumpTest)
add_subdirectory(cmake/File)
add_subdirectory(cmake/FileTest)
add_subdirectory(cmake/GTestLibGlobals)
add_subdirectory(cmake/GUIApp)
add_subdirectory(cmake/Game)
add_subdirectory(cmake/GeomDBase)
add_subdirectory(cmake/GroffBuild)
add_subdirectory(cmake/GroffExp)
add_subdirectory(cmake/InitGUIApp)
add_subdirectory(cmake/InitGUIApp2)
add_subdirectory(cmake/LZSS)
add_subdirectory(cmake/Loader)
add_subdirectory(cmake/LoaderTest)
add_subdirectory(cmake/Math)
add_subdirectory(cmake/MathTest)
add_subdirectory(cmake/Physics)
add_subdirectory(cmake/PhysicsTest)
add_subdirectory(cmake/PipelineTest)
add_subdirectory(cmake/PolyTest)
add_subdirectory(cmake/ProcessorDetect)
add_subdirectory(cmake/QuantizerTool)
add_subdirectory(cmake/QuantizerToolCLI)
add_subdirectory(cmake/RegToIniConverter)
add_subdirectory(cmake/Render3D)
add_subdirectory(cmake/ScreenRenderDWI)
add_subdirectory(cmake/Std)
add_subdirectory(cmake/StdTest)
add_subdirectory(cmake/System)
add_subdirectory(cmake/SystemTest)
add_subdirectory(cmake/TweakNvidia128)
add_subdirectory(cmake/TweakTrespass)
add_subdirectory(cmake/View)
add_subdirectory(cmake/WaveTest)
add_subdirectory(cmake/WinShell)
add_subdirectory(cmake/trespass)

# External dependencies
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)
FetchContent_MakeAvailable(Catch2)
set_target_properties(Catch2WithMain PROPERTIES FOLDER "Tests/Catch2")

option(DEACTIVATE_BROKEN_PROJECTS "Exclude known broken targets from default builds" TRUE)

if(DEACTIVATE_BROKEN_PROJECTS)
    set(BROKEN_PROJECTS
        AudioTest Bugs BumpTest CollisionEditor Examples
        FastBumpTest InitGUIApp PolyTest ProcessorDetect
        PipelineTest QuantizerToolCLI TweakTrespass WaveTest
    )
    foreach(broken ${BROKEN_PROJECTS})
        set_target_properties(${broken} PROPERTIES
            EXCLUDE_FROM_ALL TRUE
            EXCLUDE_FROM_DEFAULT_BUILD TRUE
        )
    endforeach()
endif()

