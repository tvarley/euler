#include "euler009.cpp"

namespace{
  TEST(Prob009,Known001){
    EXPECT_EQ(31875000,special_pyg_brute());
  }

  TEST(Prob009,Known002){
    EXPECT_EQ(31875000,special_pyg_opt());
  }

  TEST(Prob009,Perf001){

    static const int ITER = 1000;

    typedef std::chrono::high_resolution_clock my_clock;
    typedef std::chrono::milliseconds timer_res;

    uint64_t a,b;
    auto p1 = my_clock::now();
    for( int i = 0 ; i < ITER; i++ ){
      a = special_pyg_brute();
    }
    auto p2 = my_clock::now();

    auto a1 = std::chrono::duration_cast<timer_res>(p2-p1);
    std::cout << "Brute force took: " << a1.count() << " μs" << std::endl;

    p1 = my_clock::now();
    for( int i = 0 ; i < ITER; i++ ){
      b = special_pyg_opt();
    }
    p2 = my_clock::now();

    auto a2 = std::chrono::duration_cast<timer_res>(p2-p1);
    std::cout << "Opt 001 took: " << a2.count() << " μs" << std::endl;

    auto delta = static_cast<float>(a1.count()) / static_cast<float>(a2.count()) * 100;
    std::cout << "Delta: " << delta << "%" << std::endl;

    if( a2 < a1 )SUCCEED();
    //FAIL();
  }

};
