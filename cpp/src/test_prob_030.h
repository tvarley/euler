#include "euler030.cpp"

TEST_CASE("Prob030 Small", "[Prob030]"){
  // For upper 1000, should find some
  int sum = 0;
  for (int i = 2; i <= 1000; ++i) {
      if (sum_of_fifth_powers_of_digits(i) == i) {
          sum += i;
      }
  }
  REQUIRE(sum == 0);  // No such numbers under 1000 probably
}

TEST_CASE("Prob030 Answer", "[Prob030]"){
  REQUIRE(sum_digit_fifth_powers() == 443839);
}