#include "euler016.cpp"
TEST_CASE("Prob016 Small", "[Prob016]"){
    REQUIRE(power_digit_sum(15) == 26);
  }
TEST_CASE("Prob016 Answer", "[Prob016]"){
    REQUIRE(power_digit_sum(1000) == 1366);
  }
