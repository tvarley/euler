#include "euler027.cpp"

TEST_CASE("Prob027 Small", "[Prob027]"){
  REQUIRE(quadratic_primes_max_product(10, 50) == -235);  // a=-5, b=47 gives 43 primes
}

TEST_CASE("Prob027 Answer", "[Prob027]"){
  REQUIRE(quadratic_primes_max_product(1000, 1000) == -59231);
}