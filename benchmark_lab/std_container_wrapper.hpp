#pragma once

#include <map>
#include <unordered_map>
#include <vector>

template <typename KeyT, typename ValueT>
struct StdUnorderedMapWrapper {
    std::unordered_map<KeyT, ValueT> theContainer{};

    using value_type = ValueT;

    constexpr void add(const KeyT& aKey, const ValueT& aValue) {
        theContainer.emplace(aKey, aValue);
    }

    constexpr ValueT& lookup(const KeyT& aKey) { return theContainer.at(aKey); }
};

template <typename KeyT, typename ValueT>
struct StdMapWrapper {
    std::map<KeyT, ValueT> theContainer{};

    using value_type = ValueT;

    constexpr void add(const KeyT& aKey, const ValueT& aValue) {
        theContainer.emplace(aKey, aValue);
    }

    constexpr ValueT& lookup(const KeyT& aKey) { return theContainer.at(aKey); }
};

template <typename KeyT, typename ValueT>
struct StdVectorWithSafeAccessWrapper {
    std::vector<ValueT> theContainer{};

    using value_type = ValueT;

    constexpr void add(const KeyT& aKey, const ValueT& aValue) {
        theContainer.emplace_back(aValue);
    }

    constexpr ValueT& lookup(const KeyT& aKey) { return theContainer.at(aKey); }
};

template <typename KeyT, typename ValueT>
struct StdVectorWithoutSafeAccessWrapper {
    std::vector<ValueT> theContainer{};

    using value_type = ValueT;

    constexpr void add(const KeyT& aKey, const ValueT& aValue) {
        theContainer.emplace_back(aValue);
    }

    constexpr ValueT& lookup(const KeyT& aKey) { return theContainer[aKey]; }
};
