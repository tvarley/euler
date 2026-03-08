#include "euler006.cpp"
TEST_CASE("Prob006 Small", "[Prob006]"){
    REQUIRE(sum_squares(10) == 2640);
  }
TEST_CASE("Prob006 Answer", "[Prob006]"){
    REQUIRE(sum_squares(100) == 25164150);
  }
