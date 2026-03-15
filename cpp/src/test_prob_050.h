#include "euler050.cpp"

TEST_CASE("Prob050 Answer", "[Prob050]"){
    REQUIRE(consecutive_prime_sum() == 997651);
}