#include <benchmark/benchmark.h>
#include "analytics.hpp"

static void BM_Add(benchmark::State& state)
{
    for (auto _: state)
    {
        benchmark::DoNotOptimize(Add(2, 3));
    }
}

BENCHMARK(BM_Add);
BENCHMARK_MAIN();