#include <chrono>

#include "euler008.cpp"  // TODO: Split and inline

namespace{
  TEST(Prob008,Known001){
    EXPECT_EQ(5832,largest_product_brute(4));
  }
  TEST(Prob008,Known002){
    EXPECT_EQ(5832,largest_product_opt<4>());
  }
  TEST(Prob008,Answer001){
    EXPECT_EQ(23514624000,largest_product_brute(13));
  }
  TEST(Prob008,Answer002){
    EXPECT_EQ(23514624000,largest_product_opt<13>());
  }

  TEST(Prob008,Perf001){

    typedef std::chrono::high_resolution_clock my_clock;
    typedef std::chrono::microseconds timer_res;

    uint64_t a,b;
    auto p1 = my_clock::now();
    for( int i = 0 ; i < 100000; i++ ){
      a = largest_product_brute(13);
    }
    auto p2 = my_clock::now();

    auto a1 = std::chrono::duration_cast<timer_res>(p2-p1);
    std::cout << "Brute force took: " << a1.count() << " μs" << std::endl;

    p1 = my_clock::now();
    for( int i = 0 ; i < 100000; i++ ){
      b = largest_product_opt<13>();
    }
    p2 = my_clock::now();

    auto a2 = std::chrono::duration_cast<timer_res>(p2-p1);
    std::cout << "Opt 001 took: " << a2.count() << " μs" << std::endl;

    std::cout << "Delta: " << static_cast<float>(a1.count()) / static_cast<float>(a2.count()) << std::endl;

    if( a2 < a1 )SUCCEED();
    // FAIL();
  }
};
