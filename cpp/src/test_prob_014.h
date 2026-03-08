#include "euler014.cpp"
TEST_CASE("Prob014 ", "[Prob014]"){
    REQUIRE(count_collatz_terms_opt(13 == 10 ));
  }
TEST_CASE("Prob014 ", "[Prob014]"){
    REQUIRE(count_collatz_terms_brute(13 == 10 ));
  }
TEST_CASE("Prob014 ", "[Prob014]"){
    REQUIRE(longest_collatz_sequence_brute(1000000 == 837799 ));
  }
TEST_CASE("Prob014 ", "[Prob014]"){
    REQUIRE(longest_collatz_sequence_opt(1000000 == 837799 ));
  }
