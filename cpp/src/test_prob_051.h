#include "euler051.cpp"

TEST_CASE("Prob051 Answer", "[Prob051]"){
    REQUIRE(prime_digit_replacements() == 121313);
}