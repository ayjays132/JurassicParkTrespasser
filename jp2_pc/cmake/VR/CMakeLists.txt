project(VR)

list(APPEND VR_Inc
    ${CMAKE_SOURCE_DIR}/Source/Lib/VR/VR.hpp
)

list(APPEND VR_Src
    ${CMAKE_SOURCE_DIR}/Source/Lib/VR/VR.cpp
)

if(ANDROID)
    list(APPEND VR_Src
        ${CMAKE_SOURCE_DIR}/Source/Lib/VR/android/VR_Android.cpp
    )
endif()

include_directories(
    ${CMAKE_SOURCE_DIR}/Source
    ${CMAKE_SOURCE_DIR}/Source/gblinc
    ${CMAKE_SOURCE_DIR}/../Lib/GblInc
)

add_common_options()

add_library(${PROJECT_NAME} STATIC ${VR_Inc} ${VR_Src})
target_link_libraries(${PROJECT_NAME} PUBLIC Render3D)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Lib/Game)
