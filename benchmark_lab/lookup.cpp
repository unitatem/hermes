#include "benchmark/benchmark.h"
#include "benchmark_lab/abseil_container_wrapper.hpp"
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

BENCHMARK_TEMPLATE(benchmarkLookUp, AbseilFlatHashMapWrapper<int, Payload<64>>)
    ->Range(1, RangeUpperLimit);
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
benchmarkLookUp<AbseilFlatHashMapWrapper<int, Payload<64>>>/1                   16.5 ns         16.5 ns     45876207
benchmarkLookUp<AbseilFlatHashMapWrapper<int, Payload<64>>>/8                   16.6 ns         16.6 ns     42288061
benchmarkLookUp<AbseilFlatHashMapWrapper<int, Payload<64>>>/64                  16.6 ns         16.6 ns     41861715
benchmarkLookUp<AbseilFlatHashMapWrapper<int, Payload<64>>>/512                 16.6 ns         16.6 ns     41989001
benchmarkLookUp<AbseilFlatHashMapWrapper<int, Payload<64>>>/4096                17.0 ns         17.0 ns     40904262
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/1                     17.4 ns         17.4 ns     40142163
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/8                     17.6 ns         17.6 ns     39899163
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/64                    17.5 ns         17.5 ns     39731640
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/512                   17.5 ns         17.5 ns     39695225
benchmarkLookUp<StdUnorderedMapWrapper<int, Payload<64>>>/4096                  17.5 ns         17.5 ns     39794334
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/1                              14.1 ns         14.1 ns     49337294
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/8                              14.9 ns         14.9 ns     47858455
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/64                             17.7 ns         17.7 ns     39389429
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/512                            37.9 ns         37.9 ns     18436849
benchmarkLookUp<StdMapWrapper<int, Payload<64>>>/4096                           69.4 ns         69.2 ns     10011351
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/1             14.1 ns         14.1 ns     48884385
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/8             14.1 ns         14.1 ns     49355763
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/64            14.0 ns         14.0 ns     49553183
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/512           14.0 ns         14.0 ns     49194140
benchmarkLookUp<StdVectorWithSafeAccessWrapper<int, Payload<64>>>/4096          14.2 ns         14.2 ns     49645150
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/1          13.9 ns         13.9 ns     49941885
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/8          13.8 ns         13.8 ns     50142951
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/64         13.9 ns         13.9 ns     50083636
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/512        13.8 ns         13.8 ns     50168345
benchmarkLookUp<StdVectorWithoutSafeAccessWrapper<int, Payload<64>>>/4096       13.8 ns         13.8 ns     50525247
*/
// clang-format on
