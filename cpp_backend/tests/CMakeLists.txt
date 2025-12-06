add_executable(test_core ${PROJECT_SOURCE_DIR}/tests/test_core.cpp)

target_link_libraries(test_core PUBLIC core Catch2::Catch2WithMain)

add_test(NAME core_test COMMAND test_core)
