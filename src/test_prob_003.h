#include "euler003.cpp"

namespace{
  TEST(Prob003,Known001){
    EXPECT_EQ(29,largest_prime_factor_brute(13195));
  }

  TEST(Prob003,Answer){
    EXPECT_EQ(6857,largest_prime_factor_brute(600851475143));
  }
};
