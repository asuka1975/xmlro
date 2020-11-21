cmake_minimum_required(VERSION 3.16)
project(xmlro_test)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

add_executable(xmlro_test test.cpp)

target_link_libraries(xmlro_test gtest gmock -pthread gtest_main)
