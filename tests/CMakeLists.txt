enable_testing()

include(googletest/googletest.cmake)
fetch_googletest(${PROJECT_BINARY_DIR}/googletest)

add_executable(
        mwe_googletest_tests
        my_math_tests.cpp
)

target_link_libraries(
        mwe_googletest_tests
        gtest_main
        mwe_googletest_math
)

add_test(
        NAME mwe_googletest_tests
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/mwe_googletest_tests
)
