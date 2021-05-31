cmake_minimum_required(VERSION 3.0)

project(matrix)

set(HEADERS matrix.h ${CMAKE_SOURCE_DIR}/ADT.h)
set(SOURCES matrix.cpp)

add_library(matrix SHARED ${HEADERS} ${SOURCES})

target_include_directories(matrix PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
