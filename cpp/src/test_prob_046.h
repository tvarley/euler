#include "euler046.cpp"

TEST_CASE("Prob046 Answer", "[Prob046]"){
    REQUIRE(goldbach_other() == 5777);
}