#include "euler002.cpp"

namespace{
  TEST(Prob002,Answer){
    EXPECT_EQ(4613732,sum_even_fib(4000000));
  }
};
