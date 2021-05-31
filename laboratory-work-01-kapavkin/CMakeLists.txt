cmake_minimum_required(VERSION 3.0)

project(laboratory-work-01-kapavkin)

add_library(laboratory-work-01-kapavkin main.cpp)

add_subdirectory(date)
add_subdirectory(number)
add_subdirectory(adam)
add_subdirectory(matrix)

target_link_libraries(laboratory-work-01-kapavkin
  date
  number
  adam
  matrix
)

target_include_directories(laboratory-work-01-kapavkin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
