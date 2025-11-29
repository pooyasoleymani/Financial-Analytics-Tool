cmake_minimum_required(VERSION 3.10)

project(Financial-Analytics-Tool VERSION 1.0.00 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core src/core.cpp)
target_include_directories(core PUBLIC include)

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()