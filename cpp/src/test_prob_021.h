#include "euler021.cpp"
TEST_CASE("Prob021 Answer", "[Prob021]"){
    REQUIRE(amicable_numbers_sum(10000) == 31626);
  }
