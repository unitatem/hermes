#include "benchmark/benchmark.h"
#include "benchmark_lab/std_container_wrapper.hpp"

static_assert(sizeof(char) == 1);
static_assert(sizeof(int) == 4);
static_assert(sizeof(double) == 8);

template <typename ContainerT>
static void benchmarkLookUp(benchmark::State& aState) {
    ContainerT myContainer;

    const auto mySize = aState.range(0);
    for (int myI = 0; myI < mySize; ++myI) {
        myContainer.add(myI, typename ContainerT::value_type{myI});
    }

    int myIdx = 0;
    for (auto _ : aState) {
        const auto& myIt = myContainer.lookup(myIdx);
        benchmark::DoNotOptimize(myIt.thePayload[30]);

        ++myIdx;
        myIdx %= mySize;
    }
}

constexpr std::size_t RangeUpperLimit = 1 << 12;

template <std::size_t N>
struct Payload {
    constexpr Payload(const int myC) {
        for (int myI = 0; myI < static_cast<int>(N); ++myI) {
            thePayload[myI] = static_cast<char>(myC + myI);
        }
    }

    std::array<char, N> thePayload;
};

BENCHMARK_TEMPLATE(benchmarkLookUp, StdUnorderedMapWrapper<int, Payload<64>>)
    ->Range(1, RangeUpperLimit);
BENCHMARK_TEMPLATE(benchmarkLookUp, StdMapWrapper<int, Payload<64>>)
    ->Range(1, RangeUpperLimit);
BENCHMARK_TEMPLATE(benchmarkLookUp,
                   StdVectorWithSafeAccessWrapper<int, Payload<64>>)
    ->Range(1, RangeUpperLimit);
BENCHMARK_TEMPLATE(benchmarkLookUp,
                   StdVectorWithoutSafeAccessWrapper<int, Payload<64>>)
    ->Range(1, RangeUpperLimit);

// clang-format off
/*
--------------------------------------------------------------------------------------------------------------------
Benchmark                                                                          Time             CPU   Iterations
--------------------------------------------------------------------------------------------------------------------
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/1                     15.6 ns         15.6 ns     44645790
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/8                     15.1 ns         15.1 ns     46126832
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/64                    14.9 ns         14.9 ns     46487705
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/512                   14.9 ns         14.9 ns     45804075
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/4096                  14.9 ns         14.9 ns     46397081
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/1                              12.6 ns         12.6 ns     54907163
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/8                              12.6 ns         12.6 ns     54335762
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/64                             12.9 ns         12.9 ns     53006839
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/512                            14.6 ns         14.6 ns     45834606
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/4096                           58.5 ns         58.5 ns     11559119
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/1             12.6 ns         12.6 ns     54425240
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/8             12.8 ns         12.8 ns     54534693
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/64            12.6 ns         12.6 ns     53756608
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/512           12.6 ns         12.6 ns     53663340
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/4096          12.6 ns         12.6 ns     54274659
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/1          12.7 ns         12.7 ns     53059323
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/8          12.6 ns         12.6 ns     54333651
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/64         12.7 ns         12.7 ns     54062834
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/512        12.8 ns         12.8 ns     54226263
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/4096       12.8 ns         12.8 ns     53765353
*/
// clang-format on
