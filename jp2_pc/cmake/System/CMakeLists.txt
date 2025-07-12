project(System)

# Resolve jp2_pc directory for out-of-tree configuration.
get_filename_component(JP2_PC_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)

list(APPEND System_Inc
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/BitBuffer.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/W95/Com.hpp
    ${JP2_PC_SOURCE_DIR}/Source/gblinc/Config.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ConIO.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Control/Control.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/DebugConsole.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/Errors.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ExePageModify.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/FastHeap.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/FileMapping.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/FixedHeap.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/LRU.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/MemoryLog.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/PerformanceCount.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ProcessorDetect.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/Profile.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/reg.h
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/RegInit.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/Render.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/Scheduler.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/StdDialog.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ThreadControl.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/VirtualMem.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Shell/WinRenderTools.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/W95/Errors.h
    ${JP2_PC_SOURCE_DIR}/Source/Lib/W95/WinAlias.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/W95/WinInclude.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/Timer.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ThreadActionBase.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/FileEx.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/Textout.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/P5/Msr.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/IniFile.hpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/RegToIni.hpp
)

list(APPEND System_Src
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/BitBuffer.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/W95/Com.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ConIO.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Control/Control.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/DebugConsole.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/Errors.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/ExePageModify.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/FastHeap.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/FileEx.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/FileMapping.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/FixedHeap.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/LRU.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/MemoryLog.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/PerformanceCount.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ProcessorDetect.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/Profile.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/reg.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/RegInit.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/Render.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/Scheduler.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/StdDialog.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/Textout.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/ThreadControl.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/W95/Timer.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/VirtualMem.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Shell/WinRenderTools.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/IniFile.cpp
    ${JP2_PC_SOURCE_DIR}/Source/Lib/Sys/RegToIni.cpp
)

list(APPEND System_Rsc
    ${JP2_PC_SOURCE_DIR}/Source/Lib/W95/Errors.rc
)

include_directories(
    ${JP2_PC_SOURCE_DIR}/Source
    ${JP2_PC_SOURCE_DIR}/Source/gblinc
)

add_common_options()

add_library(${PROJECT_NAME} STATIC ${System_Inc} ${System_Src} ${System_Rsc} )

option(USE_SDL_CONTROLLER "Use SDL2 for modern game controller input" OFF)
if(USE_SDL_CONTROLLER)
    find_package(SDL2 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2)
    target_compile_definitions(${PROJECT_NAME} PUBLIC USE_SDL_CONTROLLER)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Lib/Util)
