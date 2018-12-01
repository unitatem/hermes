enable_testing()

include(googletest/googletest.cmake)
fetch_googletest(${PROJECT_BINARY_DIR}/googletest)

add_executable(
        dedal_tests
        my_math_tests.cpp
)

target_link_libraries(
        dedal_tests
        gtest_main
        dedal_core
)

add_test(
        NAME dedal_tests
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/dedal_tests
)