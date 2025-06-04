project(VR)

list(APPEND VR_Inc
    ${CMAKE_SOURCE_DIR}/Source/Lib/VR/VR.hpp
)

list(APPEND VR_Src
    ${CMAKE_SOURCE_DIR}/Source/Lib/VR/VR.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/Source
    ${CMAKE_SOURCE_DIR}/Source/gblinc
)

add_common_options()

add_library(${PROJECT_NAME} STATIC ${VR_Inc} ${VR_Src})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Lib/Game)
