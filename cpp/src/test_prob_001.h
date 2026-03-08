#include "euler001.cpp"

TEST_CASE("Prob001 Know001", "[Prob001]"){
  REQUIRE(sum_natural_35(10) == 23);
}

TEST_CASE("Prob001 Answer", "[Prob001]"){
  REQUIRE(sum_natural_35(1000) == 233168);
}
