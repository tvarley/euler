#include "euler015.cpp"
TEST_CASE("Prob015 Small", "[Prob015]"){
    REQUIRE(lattice_path(2) == 6);
  }
TEST_CASE("Prob015 Answer", "[Prob015]"){
    REQUIRE(lattice_path(20) == 137846528820);
  }
