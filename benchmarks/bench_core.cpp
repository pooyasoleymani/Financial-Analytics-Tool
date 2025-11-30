#include <benchmark/benchmark.h>
#include "core.hpp"

static void BM_Add(benchmark::State& state)
{
    for (auto _: state)
    {
        benchmark::DoNotOptimize(add(2, 3));
    }
}

BENCHMARK(BM_Add);
BENCHMARK_MAIN();