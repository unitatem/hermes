#pragma once

template <typename DerivedT>
struct Orderable {
    friend bool operator<(const DerivedT& lhs, const DerivedT& rhs) {
        return lhs.value() < rhs.value();
    }
};