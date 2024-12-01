cmake_minimum_required(VERSION 3.10)
project(day_one)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(INPUT_TEXT "${CMAKE_SOURCE_DIR}/input.txt")
set(INPUT_DEST "${CMAKE_BINARY_DIR}/input.txt")


file(GLOB SOURCES "${SRC_DIR}/*.cpp")
include_directories("${INCLUDE_DIR}")

add_executable(${PROJECT_NAME} ${SOURCES})

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${INPUT_TEXT} ${INPUT_DEST}
    COMMENT "Copying input file to .exe dir"
)

