#include <catch2/catch_test_macros.hpp>
#include "analytics.hpp"

TEST_CASE("addition test", "[core]")
{
    REQUIRE(Add(2, 3) == 5);
}