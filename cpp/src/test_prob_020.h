#include "euler020.cpp"

namespace{
  TEST(Prob020,Known001){
    EXPECT_EQ(27,factorial_digit_sum(10));
  }

  TEST(Prob020,Answer01){
    EXPECT_EQ(648,factorial_digit_sum(100));
  }

  TEST(Prob020,Known002){
    EXPECT_EQ(27,factorial_digit_sum_opt(10));
  }

  TEST(Prob020,Answer02){
    EXPECT_EQ(648,factorial_digit_sum_opt(100));
  }

  TEST(Prob020,Perf001){

    typedef std::chrono::high_resolution_clock my_clock;
    typedef std::chrono::microseconds timer_res;

    uint64_t a,b;
    auto p1 = my_clock::now();
    for( int i = 0 ; i < 1000; i++ ){
      a = factorial_digit_sum(100);
    }
    auto p2 = my_clock::now();

    auto a1 = std::chrono::duration_cast<timer_res>(p2-p1);
    // auto a1 = p2-p1;
    std::cout << "Brute force took: " << a1.count() << " μs" << std::endl;

    p1 = my_clock::now();
    for( int i = 0 ; i < 1000; i++ ){
      b = factorial_digit_sum_opt(100);
    }
    p2 = my_clock::now();

    auto a2 = std::chrono::duration_cast<timer_res>(p2-p1);
    // auto a2 = p2-p1;
    std::cout << "Opt 001 took: " << a2.count() << " μs" << std::endl;

    if( a2 < a1 )SUCCEED();
    // FAIL();
  }
};
