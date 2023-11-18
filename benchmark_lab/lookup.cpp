#include <map>
#include <unordered_map>
#include <vector>

#include "benchmark/benchmark.h"

constexpr std::size_t RangeUpperLimit = 1 << 12;

template <typename MapT>
static void benchmarkMapLookUp(benchmark::State& aState) {
    const auto mySize = aState.range(0);

    MapT myContainer;
    for (int myI = 0; myI < mySize; ++myI) {
        myContainer.emplace(myI, myI);
    }

    auto myIdx = 0;
    for (auto _ : aState) {
        const auto myIt = myContainer[myIdx];
        benchmark::DoNotOptimize(myIt);

        ++myIdx;
        myIdx %= mySize;
    }
}

BENCHMARK_TEMPLATE(benchmarkMapLookUp, std::unordered_map<int, int>)
    ->Range(1, RangeUpperLimit);
BENCHMARK_TEMPLATE(benchmarkMapLookUp, std::map<int, int>)
    ->Range(1, RangeUpperLimit);

enum class UseSafeLookUp {
    No,
    Yes,
};

template <UseSafeLookUp UseSafeLookUpV>
static void benchmarkVectorSafeLookUp(benchmark::State& aState) {
    const auto mySize = aState.range(0);

    std::vector<int> myContainer;
    for (int myI = 0; myI < mySize; ++myI) {
        myContainer.emplace_back(myI);
    }

    auto myIdx = 0;
    for (auto _ : aState) {
        if constexpr (UseSafeLookUpV == UseSafeLookUp::Yes) {
            const auto myValue = myContainer.at(myIdx);
            benchmark::DoNotOptimize(myValue);
        } else {
            const auto myValue = myContainer[myIdx];
            benchmark::DoNotOptimize(myValue);
        }

        ++myIdx;
        myIdx %= mySize;
    }
}

BENCHMARK_TEMPLATE(benchmarkVectorSafeLookUp, UseSafeLookUp::Yes)
    ->Range(1, RangeUpperLimit);
BENCHMARK_TEMPLATE(benchmarkVectorSafeLookUp, UseSafeLookUp::No)
    ->Range(1, RangeUpperLimit);
