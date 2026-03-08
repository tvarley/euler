#include "euler002.cpp"
TEST_CASE("Prob002 Answer", "[Prob002]"){
    REQUIRE(sum_even_fib(4000000) == 4613732);
  }
