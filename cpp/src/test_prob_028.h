#include "euler028.cpp"

TEST_CASE("Prob028 Small", "[Prob028]"){
  REQUIRE(spiral_diagonal_sum(5) == 101);
}

TEST_CASE("Prob028 Answer", "[Prob028]"){
  REQUIRE(spiral_diagonal_sum(1001) == 669171001);
}