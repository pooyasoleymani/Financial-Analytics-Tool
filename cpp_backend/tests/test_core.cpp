#include <catch2/catch_test_macros.hpp>
#include "core.hpp"

TEST_CASE("addition test", "[core]")
{
    REQUIRE(add(2, 3) == 5);
}