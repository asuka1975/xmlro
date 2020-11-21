cmake_minimum_required(VERSION 3.16)
project(xmlro)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_library(xmlro src/dummy.cpp)

target_include_directories(xmlro PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)