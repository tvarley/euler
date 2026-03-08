#include "euler020.cpp"
TEST_CASE("Prob020 ", "[Prob020]"){
    REQUIRE(factorial_digit_sum(10 == 27));
  }
TEST_CASE("Prob020 ", "[Prob020]"){
    REQUIRE(factorial_digit_sum(100 == 648));
  }
TEST_CASE("Prob020 ", "[Prob020]"){
    REQUIRE(factorial_digit_sum_opt(10 == 27));
  }
TEST_CASE("Prob020 ", "[Prob020]"){
    REQUIRE(factorial_digit_sum_opt(100 == 648));
  }
TEST_CASE("Prob020 ", "[Prob020]"){

    typedef std::chrono::high_resolution_clock my_clock;
    typedef std::chrono::microseconds timer_res;

    uint64_t a,b;
    auto p1 = my_clock::now();
    for( int i = 0 ; i < 1000; i++ ){
      a = factorial_digit_sum(100);
    }
    auto p2 = my_clock::now();

    auto a1 = std::chrono::duration_cast<timer_res>(p2-p1);
    std::cout << "Brute force took: " << a1.count() << " μs" << std::endl;

    p1 = my_clock::now();
    for( int i = 0 ; i < 1000; i++ ){
      b = factorial_digit_sum_opt(100);
    }
    p2 = my_clock::now();

    auto a2 = std::chrono::duration_cast<timer_res>(p2-p1);
    std::cout << "Opt 001 took: " << a2.count() << " μs" << std::endl;

    auto delta = static_cast<float>(a1.count()) / static_cast<float>(a2.count()) * 100;
    std::cout << "Delta: " << delta << "%" << std::endl;

    if( a2 < a1 )SUCCEED();
    // FAIL();
  }
