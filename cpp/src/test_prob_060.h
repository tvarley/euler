#include "euler060.cpp"
TEST_CASE("Prob060 Answer", "[Prob060]"){
    REQUIRE(prime_pair_sets() == 26033);
}