#pragma once

#include <utility>

template <typename T>
class StrongType {
public:
    using value_type = T;

    constexpr StrongType(T aData) : theData{std::forward<T>(aData)} {}

    constexpr T value() const { return theData; }

private:
    T theData;
};
