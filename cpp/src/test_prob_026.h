#include "euler026.cpp"

TEST_CASE("Prob026 Known001", "[Prob026]"){
  REQUIRE(longest_reciprocal_cycle(10) == 7);
}

TEST_CASE("Prob026 Answer", "[Prob026]"){
  REQUIRE(longest_reciprocal_cycle(1000) == 983);
}