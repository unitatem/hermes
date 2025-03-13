#pragma once

template <typename DerivedT>
struct Addable {
    friend DerivedT operator+(const DerivedT& lhs, const DerivedT& rhs) {
        return DerivedT{lhs.value() + rhs.value()};
    }
};