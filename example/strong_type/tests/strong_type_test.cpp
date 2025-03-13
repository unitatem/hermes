#include "example/strong_type/strong_type.hpp"

#include "example/strong_type/addable.hpp"
#include "example/strong_type/orderable.hpp"
#include "gtest/gtest.h"

TEST(StrongType, valueCtor) {
    {
        StrongType<int> a{5};
        ASSERT_EQ(5, a.value());
    }
    {
        StrongType<double> a{-4.2};
        ASSERT_EQ(-4.2, a.value());
    }
}

template <typename L, typename R>
concept IsAddable = requires(L lhs, R rhs) { lhs + rhs; };

struct AddableType : public StrongType<int>, public Addable<AddableType> {
    using StrongType<int>::StrongType;
};

TEST(Addable, compile) {
    static_assert(IsAddable<AddableType, AddableType>, "operator");
}

TEST(Addable, operator) {
    AddableType a{5};
    AddableType b{10};

    auto result = a + b;

    static_assert(std::is_same_v<AddableType, decltype(result)>, "result");
    ASSERT_EQ(15, result.value());
}

template <typename L, typename R>
concept IsOrderable = requires(L lhs, R rhs) {
    { lhs < rhs } -> std::same_as<bool>;
};

struct OrderableType : public StrongType<int>, public Orderable<OrderableType> {
    using StrongType<int>::StrongType;
};

TEST(Orderable, compile) {
    static_assert(IsOrderable<OrderableType, OrderableType>, "operator");
}

TEST(Orderable, operator) {
    OrderableType a{5};
    OrderableType b{10};

    auto result = a < b;

    static_assert(std::is_same_v<bool, decltype(result)>, "result");
    ASSERT_TRUE(result);
}
