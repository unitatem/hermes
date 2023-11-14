#include <iostream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

int fun_lambda_with_static() {
    auto fun = []() -> int {
        static int cnt = 0;
        std::cout << "fun_lambda_with_static::lambda()"
                  << "\n";
        return ++cnt;
    };

    fun();
    return fun();
}

TEST(LambdaTest, static_in_lambda_is_initialized_only_once) {
    EXPECT_EQ(2, fun_lambda_with_static());
    EXPECT_EQ(4, fun_lambda_with_static());
}

int fun_lambda_with_capture() {
    auto fun = [cnt = 0]() mutable -> int {
        std::cout << "fun_lambda_with_capture::lambda()"
                  << "\n";
        return ++cnt;
    };

    fun();
    return fun();
}

TEST(LambdaTest, capture_in_lambda_is_captured_once_per_lambda_instance) {
    EXPECT_EQ(2, fun_lambda_with_capture());
    EXPECT_EQ(2, fun_lambda_with_capture());
}

static int lifetime = 0;
int fun_lambda_static_init() {
    lifetime = 2;
    auto fun = []() -> int {
        std::cout << "fun_lambda_static_init::lambda()"
                  << "\n";
        static int store = lifetime;
        return store;
    };

    lifetime = 3;
    fun();
    lifetime = 4;
    return fun();
}

TEST(LambdaTest, static_in_lambda_initialized_during_first_call) {
    lifetime = 1;
    EXPECT_EQ(3, fun_lambda_static_init());
    EXPECT_EQ(3, fun_lambda_static_init());
}
