cmake_minimum_required(VERSION 3.0)

project(tree)

set(HEADERS tree.h ${CMAKE_SOURCE_DIR}/ADT.h)
set(SOURCES tree.cpp)

add_library(tree SHARED ${HEADERS} ${SOURCES})

target_include_directories(tree PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(tree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
