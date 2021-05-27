#include "euler024.cpp"

namespace{
  TEST(Prob024,factorial_5){
    EXPECT_EQ(120,factorial(5));
  }

  TEST(Prob024,factorial_12){
    EXPECT_EQ(479001600,factorial(12));
  }

  // TEST(Prob024,lexicographic_permutations_cheat){
  //   EXPECT_EQ(2783915460,lexicographic_permutations_cheat("0123456789"));
  // }

  // TEST(Prob024,Answer){
  //   EXPECT_EQ(4179871,non_abundunt_sums(12));
  // }
};
