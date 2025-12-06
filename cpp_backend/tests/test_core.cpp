#include <catch2/catch_test_macros.hpp>
#include "analytics.hpp"

using namespace Analytics;

TEST_CASE("Calculate VAT", "[core]")
{
    REQUIRE(CalculateVAT(2.0, 3.0) == 6.0);
}