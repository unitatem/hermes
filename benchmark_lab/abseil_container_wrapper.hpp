#pragma once

#include "absl/container/flat_hash_map.h"

template <typename KeyT, typename ValueT>
struct AbseilFlatHashMapWrapper {
    absl::flat_hash_map<KeyT, ValueT> theContainer{};

    using value_type = ValueT;

    constexpr void add(const KeyT& aKey, const ValueT& aValue) {
        theContainer.emplace(aKey, aValue);
    }

    constexpr ValueT& lookup(const KeyT& aKey) { return theContainer.at(aKey); }
};
