cmake_minimum_required(VERSION 3.10)

project(Financial-Analytics-Tool VERSION 1.0.00 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "build shared library" OFF)

add_library(core src/core.cpp)
target_include_directories(core PUBLIC include)

add_executable(cli apps/cli_app.cpp)
target_link_libraries(cli PRIVATE core)

include(CTest)

include(CPack)
set(CPACK_GENERATOR "ZIP;TGZ")
set(CPACK_PACKAGE_NAME "Financial-Analytics-Tool")
set(CPACK_PACKAGE_VERSION "0.9.0")
set(CPACK_PACKAGE_CONTACT "pooya@example.com")

# include(FetchContent)

# FetchContent_Declare(
# Catch2
# GIT_REPOSITORY https://github.com/catchorg/Catch2.git
# GIT_TAG v3.5.2
# )

# FetchContent_MakeAvailable(Catch2)

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    add_subdirectory(externals/Catch2)
    enable_testing()
    add_subdirectory(tests)
endif()

option(BUILD_BENCHMARKS "Build benchmarks" OFF)
if(BUILD_BENCHMARKS)
  add_subdirectory(externals/benchmark)
  add_executable(bench_core benchmarks/bench_core.cpp)
  target_link_libraries(bench_core PRIVATE core benchmark)
endif()