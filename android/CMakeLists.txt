set(ENV_ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets/env")

add_library(jp2_android SHARED
    jp2_pc/Source/Lib/VR/VR.cpp
    jp2_pc/Source/Lib/Renderer/EnvironmentModern.cpp
)

target_include_directories(jp2_android PRIVATE
    ${CMAKE_SOURCE_DIR}/jp2_pc/Source/Lib/Renderer
    ${CMAKE_SOURCE_DIR}/jp2_pc/ThirdParty/stb
    ${ANDROID_NDK}/sources/android/native_app_glue
)

find_library(EGL_LIB EGL)
find_library(GLESv3_LIB GLESv3)

target_link_libraries(jp2_android PRIVATE
    android
    ${EGL_LIB}
    ${GLESv3_LIB}
)

file(GLOB ENV_FILES "${ENV_ASSETS_DIR}/*.png")
foreach(img ${ENV_FILES})
    add_android_asset(jp2_android "${img}" "assets/env/${img}")
endforeach()

file(GLOB DDS_FILES "${CMAKE_SOURCE_DIR}/assets/Data/Textures/*.dds")
foreach(dds ${DDS_FILES})
    add_android_asset(jp2_android "${dds}" "assets/Data/Textures/${dds}")
endforeach()
