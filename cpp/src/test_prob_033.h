#include "euler033.cpp"

TEST_CASE("Prob033 Answer", "[Prob033]"){
    REQUIRE(digit_cancelling_fractions() == 100);
}