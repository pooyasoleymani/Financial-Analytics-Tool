cmake_minimum_required(VERSION 3.10)

project(Financial-Analytics-Tool VERSION 1.0.00 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "build shared library" ON)

add_library(core ${CMAKE_SOURCE_DIR}/cpp_backend/src/analytics.cpp)
target_include_directories(core PUBLIC ${CMAKE_SOURCE_DIR}/cpp_backend/include)

add_executable(cli ${CMAKE_SOURCE_DIR}/cpp_backend/apps/cli_app.cpp)
target_link_libraries(cli PRIVATE core)

include(CTest)

include(CPack)
set(CPACK_GENERATOR "ZIP;TGZ")
set(CPACK_PACKAGE_NAME "Financial-Analytics-Tool")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "pooyasoleyamaninejad@gmail.com")

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
    add_subdirectory(${CMAKE_SOURCE_DIR}/cpp_backend/externals/Catch2)
    enable_testing()
    add_subdirectory(${CMAKE_SOURCE_DIR}/cpp_backend/tests)
endif()

option(BUILD_BENCHMARKS "Build benchmarks" ON)
if(BUILD_BENCHMARKS)
  add_subdirectory(${PROJECT_SOURCE_DIR}/cpp_backend/externals/benchmark)
  add_executable(bench_core ${CMAKE_SOURCE_DIRURCE_DIR}/cpp_backend/benchmarks/bench_core.cpp)
  target_link_libraries(bench_core PRIVATE core benchmark)
endif()

add_subdirectory(${PROJECT_SOURCE_DIR}/cpp_backend/externals/pybind11)
SET(PYBIND11_PYTHON_VERSION "3.13")

pybind11_add_module(
  finanalytics 
  ${PROJECT_SOURCE_DIR}/binding/pybind_module.cpp
  ${PROJECT_SOURCE_DIR}/cpp_backend/src/analytics.cpp
  )

target_include_directories(
  finanalytics PRIVATE 
  ${PROJECT_SOURCE_DIR}/cpp_backend/include 
  ${PROJECT_SOURCE_DIR}/cpp_backend/externals/pybind11/include
  )

  add_custom_command(
    TARGET finanalytics POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:finanalytics>
    ${CMAKE_SOURCE_DIR}/pyqt_frontend/
  )
