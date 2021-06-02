#include "euler024.cpp"

namespace{
  TEST(Prob024,lexicographic_permutations_cheat){
    EXPECT_EQ("2783915460",lexicographic_permutations_cheat("0123456789"));
  }

  TEST(Prob024,lexicographic_permutations){
    EXPECT_EQ("2783915460",lexicographic_permutations("0123456789"));
  }
};
