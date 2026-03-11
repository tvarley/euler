#include "euler037.cpp"

TEST_CASE("Prob037 Answer", "[Prob037]"){
    REQUIRE(truncatable_primes() == 748317);
}