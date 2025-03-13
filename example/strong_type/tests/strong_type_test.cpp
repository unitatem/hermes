#include "example/strong_type/strong_type.hpp"

#include "example/strong_type/addable.hpp"
#include "example/strong_type/orderable.hpp"
#include "gtest/gtest.h"

TEST(StrongType, strong) {
    using Meter = StrongTypeFactory<int, struct MeterTag>;
    using Yard = StrongTypeFactory<int, struct YardTag>;
    static_assert(!std::is_same_v<Meter, Yard>, "strong");

    static_assert(sizeof(Meter) == sizeof(int), "size");

    static_assert(std::is_same_v<Meter::value_type, int>, "value_type");
}

TEST(StrongType, valueCtor) {
    {
        using Meter = StrongTypeFactory<int, struct MeterTag>;
        Meter a{5};
        ASSERT_EQ(5, a.value());
    }
    {
        using Celsius = StrongTypeFactory<double, struct CelsiusTag>;
        Celsius a{-4.2};
        ASSERT_EQ(-4.2, a.value());
    }
}

template <typename L, typename R>
concept IsAddable = requires(L lhs, R rhs) { lhs + rhs; };

using AddableType = StrongTypeFactory<int, struct AddableTypeTag, Addable>;

TEST(Addable, compile) {
    static_assert(IsAddable<AddableType, AddableType>, "IsAddable");

    static_assert(sizeof(AddableType) == sizeof(int), "size");
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

using OrderableType =
    StrongTypeFactory<int, struct OrderableTypeTag, Orderable>;

TEST(Orderable, compile) {
    static_assert(IsOrderable<OrderableType, OrderableType>, "IsOrderable");

    static_assert(sizeof(OrderableType) == sizeof(int), "size");
}

TEST(Orderable, operator) {
    OrderableType a{5};
    OrderableType b{10};

    auto result = a < b;

    static_assert(std::is_same_v<bool, decltype(result)>, "result");
    ASSERT_TRUE(result);
}

using CompositeType =
    StrongTypeFactory<int, struct CompositeTypeTag, Addable, Orderable>;

TEST(Composite, compile) {
    static_assert(IsAddable<AddableType, AddableType>, "IsAddable");
    static_assert(IsOrderable<OrderableType, OrderableType>, "IsOrderable");

    static_assert(sizeof(CompositeType) == sizeof(int), "size");
}

TEST(Composite, operator) {
    CompositeType a{5};
    CompositeType b{10};

    EXPECT_EQ(15, (a + b).value());
    EXPECT_LT(a, b);
}