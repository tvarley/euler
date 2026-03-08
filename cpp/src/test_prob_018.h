#include "euler018.cpp"
TEST_CASE("Prob018 Small", "[Prob018]"){
    REQUIRE(maximum_path_sum_1(test_data_fname) == 23);
  }
TEST_CASE("Prob018 Answer", "[Prob018]"){
    REQUIRE(maximum_path_sum_1(data_fname) == 1074);
  }
