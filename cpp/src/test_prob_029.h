#include "euler029.cpp"

TEST_CASE("Prob029 Small", "[Prob029]"){
  REQUIRE(distinct_powers(5, 5) == 15);
}

TEST_CASE("Prob029 Answer", "[Prob029]"){
  REQUIRE(distinct_powers(100, 100) == 9183);
}