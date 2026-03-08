#include "euler023.cpp"
TEST_CASE("Prob023 Perfect", "[Prob023]"){
    REQUIRE(how_perfect(28) == PERFECT);
  }
TEST_CASE("Prob023 Deficient", "[Prob023]"){
    REQUIRE(how_perfect(29) == DEFICIENT);
  }
TEST_CASE("Prob023 Abundant", "[Prob023]"){
    REQUIRE(how_perfect(26640) == ABUNDENT);
  }
TEST_CASE("Prob023 Answer", "[Prob023]"){
    REQUIRE(non_abundunt_sums() == 4179871);
  }
