enable_testing()

include(googletest/googletest.cmake)
fetch_googletest(${PROJECT_BINARY_DIR}/googletest)

add_executable(${PROJECT_NAME}_mtest
        mtest_test.cpp
)

target_link_libraries(${PROJECT_NAME}_mtest
        gtest
        gmock_main
)
