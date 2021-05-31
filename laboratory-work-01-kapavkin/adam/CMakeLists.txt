cmake_minimum_required(VERSION 3.0)

project(adam)

set(HEADERS adam.h ${CMAKE_SOURCE_DIR}/ADT.h)
set(SOURCES adam.cpp)

add_library(adam SHARED ${HEADERS} ${SOURCES})

target_include_directories(adam PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(adam PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
