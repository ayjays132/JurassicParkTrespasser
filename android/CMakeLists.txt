cmake_minimum_required(VERSION 3.10)
project(JPT_Android)

option(ENABLE_OCULUS_QUEST_SUPPORT "Enable Oculus Quest VR support" ON)
option(ENABLE_MODERN_ENV_RENDER "Enable Modern Environment Renderer (Quest only)" OFF)

if(NOT ANDROID_NDK)
    message(FATAL_ERROR "ANDROID_NDK environment variable is not set!")
endif()

set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
set(CMAKE_ANDROID_PLATFORM android-24)
set(CMAKE_ANDROID_NDK ${ANDROID_NDK})
set(CMAKE_ANDROID_STL_TYPE c++_static)

set(REPO_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

include_directories(
    ${REPO_ROOT}/jp2_pc/Source
    ${REPO_ROOT}/jp2_pc/Source/gblinc
    ${REPO_ROOT}/ThirdParty/stb
    ${REPO_ROOT}/jp2_pc/Source/Lib/VR
)

set(ANDROID_SOURCES
    ${REPO_ROOT}/jp2_pc/Source/Lib/VR/VR.cpp
    ${REPO_ROOT}/jp2_pc/Source/Lib/VR/android/VR_Android.cpp
)

add_library(jpt_android SHARED ${ANDROID_SOURCES})

target_link_libraries(jpt_android PRIVATE android log EGL GLESv3)

set_target_properties(jpt_android PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
