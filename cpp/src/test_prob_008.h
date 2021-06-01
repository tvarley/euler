#include <chrono>

#include "euler008.cpp"  // TODO: Split and inline
#include "simple_timer.h"

namespace{
  TEST(Prob008,Known001) {
    EXPECT_EQ(5832,largest_product_brute(4));
  }
  TEST(Prob008,Known002) {
    EXPECT_EQ(5832,largest_product_opt<4>());
  }
  TEST(Prob008,Answer001) {
    EXPECT_EQ(23514624000,largest_product_brute(13));
  }
  TEST(Prob008,Answer002) {
    EXPECT_EQ(23514624000,largest_product_opt<13>());
  }

  TEST(Prob008,Perf001) {
    double a1{};
    double a2{};
    {
      simple_timer timer("Largest Product Brute"); 
      for( int i = 0 ; i < 100000; i++ ){
        largest_product_brute(13);
      }
      a1 = timer.stop();
    }
    std::cout << "Largest Product Brute: " << a1 << "μs (" << a1 / 1000000 << ")" << std::endl;

    {
      simple_timer timer("Largest Product Optimized"); 
      for( int i = 0 ; i < 100000; i++ ){
        largest_product_opt<13>();
      }
      a2 = timer.stop();
    }
    std::cout << "Largest Product Optimized: " << a2 << "μs (" << a2 / 1000000 << ")" << std::endl;

    if( a2 < a1 )SUCCEED();
    // FAIL();
  }
};
