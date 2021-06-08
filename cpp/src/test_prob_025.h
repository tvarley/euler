#include "euler025.cpp"

namespace{
  // TEST(Zbigint,simple_addition){
  //   Zbigint a{1};
  //   Zbigint a{2};
  // 
  //   EXPECT_EQ(3,a + b);
  // }

  TEST(Prob025,z1000_digit_fibinacci_number){
    EXPECT_EQ(4782,z1000_digit_fibinacci_number());
  }
};
