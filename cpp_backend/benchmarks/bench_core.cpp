#include <benchmark/benchmark.h>
#include "analytics.hpp"


using namespace Analytics;

static void BM_CalculatVAT(benchmark::State& state)
{
    for (auto _: state)
    {
        benchmark::DoNotOptimize(CalculateVAT(2.0, 3.0));
    }
}

BENCHMARK(BM_CalculatVAT);
BENCHMARK_MAIN();