#include "euler007.cpp"
TEST_CASE("Prob007 Small", "[Prob007]"){
    REQUIRE(nth_prime(6) == 13);
  }
TEST_CASE("Prob007 Answer", "[Prob007]"){
    REQUIRE(nth_prime(10001) == 104743);
  }
