#include "euler004.cpp"
TEST_CASE("Prob004 Palindrome Test", "[Prob004]"){
    REQUIRE(palindrome_test(12321));
  }
TEST_CASE("Prob004 Not Palindrome", "[Prob004]"){
    REQUIRE_FALSE(palindrome_test(1234));
  }
TEST_CASE("Prob004 Answer", "[Prob004]"){
    REQUIRE(prob004_brute_force() == 906609);
  }
