cmake_minimum_required(VERSION 3.16)
project(xmlro)

set(CMAKE_CXX_STANDARD 17)
set(XMLRO_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_library(xmlro src/dummy.cpp)

target_include_directories(xmlro PRIVATE ${XMLRO_INCLUDE_DIR})

add_subdirectory(test)