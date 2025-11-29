cmake_minimum_required(VERSION 3.10)

project(Financial-Analytics-Tool VERSION 1.0.00 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "build shared library" OFF)

add_library(core src/core.cpp)
target_include_directories(core PUBLIC include)

add_executable(cli apps/cli_app.cpp)
target_link_libraries(cli PRIVATE core)

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()