cmake_minimum_required(VERSION 3.0)

project(date)

set(HEADERS date.h ${CMAKE_SOURCE_DIR}/ADT.h)
set(SOURCES date.cpp)

add_library(date SHARED ${HEADERS} ${SOURCES})

target_include_directories(date PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(date PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
