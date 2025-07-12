cmake_minimum_required(VERSION 3.15) project(JPT_Android)

    option(
        ENABLE_OCULUS_QUEST_SUPPORT
        "Enable Oculus Quest VR support" ON) option(ENABLE_MODERN_ENV_RENDER
                                                    "Enable Modern Environment "
                                                    "Renderer (Quest only)" OFF)

        if (NOT ANDROID_NDK) message(
            FATAL_ERROR "ANDROID_NDK environment variable is not set!") endif()

            set(CMAKE_SYSTEM_NAME Android) set(
                CMAKE_ANDROID_ARCH_ABI arm64 -
                v8a) set(CMAKE_ANDROID_PLATFORM android -
                         24) set(CMAKE_ANDROID_NDK $ENV{
                ANDROID_NDK}) set(CMAKE_ANDROID_STL_TYPE c++ _static)

                include_directories(${CMAKE_SOURCE_DIR} / Lib /
                                    Render3D ${CMAKE_SOURCE_DIR} / Lib /
                                    GblInc ${CMAKE_SOURCE_DIR} / jp2_pc /
                                    Source / gblinc ${CMAKE_SOURCE_DIR} /
                                    ThirdParty / stb ${CMAKE_SOURCE_DIR} /
                                    jp2_pc / Source / Lib /
                                    VR ${CMAKE_SOURCE_DIR} / assets / env)

                    set(ANDROID_SOURCES ${CMAKE_SOURCE_DIR} / jp2_pc / Source /
                        Lib / VR / VR.cpp ${CMAKE_SOURCE_DIR} / Lib / Render3D /
                        Render3D.cpp ${CMAKE_SOURCE_DIR} / Lib / GblInc /
                        common.cpp ${CMAKE_SOURCE_DIR} / jp2_pc / Source /
                        main.cpp)

                        add_library(jpt_android SHARED ${ANDROID_SOURCES})

                            find_library(
                                EGL_LIB NAMES EGL PATHS ${ANDROID_NDK} /
                                    platforms / android -
                                24 / arch -
                                arm64 / usr /
                                    lib) find_library(GLESv3_LIB NAMES GLESv3
                                                              PATHS ${
                                                                  ANDROID_NDK} /
                                                          platforms / android -
                                                      24 / arch -
                                                      arm64 / usr / lib)

                                target_link_libraries(
                                    jpt_android PRIVATE android log ${
                                        EGL_LIB} ${GLESv3_LIB} Render3D)

                                    file(GLOB SKY_PNGS "${CMAKE_SOURCE_DIR}/"
                                                       "assets/env/*.png") foreach (
                                        img ${SKY_PNGS})
                                        add_android_asset(
                                            jpt_android
                                            "${img}"
                                            "assets/env/${img}") endforeach()

                                            file(GLOB TEX_DDS "${CMAKE_SOURCE_"
                                                              "DIR}/assets/"
                                                              "Data/Textures/"
                                                              "*.dds") foreach (
                                                dds ${TEX_DDS})
                                                add_android_asset(
                                                    jpt_android
                                                    "${dds}"
                                                    "assets/Data/Textures/"
                                                    "${dds}") endforeach()

                                                    set_target_properties(
                                                        jpt_android PROPERTIES
                                                            CXX_STANDARD 17 CXX_STANDARD_REQUIRED
                                                                ON)
