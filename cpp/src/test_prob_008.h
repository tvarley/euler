#include <chrono>

#include "euler008.cpp"  // TODO: Split and inline
#include "simple_timer.h"
TEST_CASE("Prob008 ", "[Prob008]"){
    REQUIRE(largest_product_brute(4 == 5832));
  }
TEST_CASE("Prob008 ", "[Prob008]"){
    REQUIRE(largest_product_opt<4>( == 5832));
  }
TEST_CASE("Prob008 ", "[Prob008]"){
    REQUIRE(largest_product_brute(13 == 23514624000));
  }
TEST_CASE("Prob008 ", "[Prob008]"){
    REQUIRE(largest_product_opt<13>( == 23514624000));
  }
TEST_CASE("Prob008 ", "[Prob008]"){
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
