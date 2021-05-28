#include "euler023.cpp"

namespace{
  TEST(Prob023,IsPerfect) {
    EXPECT_EQ(PERFECT,how_perfect(28));
  }

  TEST(Prob023,IsDeficient) {
    EXPECT_EQ(DEFICIENT,how_perfect(29));
  }

  TEST(Prob023,IsAbundent) {
    EXPECT_EQ(ABUNDENT,how_perfect(26640));
  }

  TEST(Prob023,Answer) {
    EXPECT_EQ(4179871,non_abundunt_sums());
  }
};
