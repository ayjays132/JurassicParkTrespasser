project(StdTest)

list(APPEND StdTest_Src
    ${CMAKE_SOURCE_DIR}/Source/Test/Novel/StdTest/CSetTest.cpp
)

add_common_options()

add_executable(${PROJECT_NAME} ${StdTest_Src})

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Tests/Novel)

include_directories(
    ${CMAKE_SOURCE_DIR}/Source
    ${CMAKE_SOURCE_DIR}/Source/gblinc
)

target_link_libraries( ${PROJECT_NAME}
    Std
    Catch2::Catch2WithMain
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
