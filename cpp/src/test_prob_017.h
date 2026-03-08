#include "euler017.cpp"
TEST_CASE("Prob017 Small", "[Prob017]"){
    g_letter_count = 0;
    mp_for<1,6>()();
    REQUIRE(g_letter_count == 19);
  }
TEST_CASE("Prob017 Answer", "[Prob017]"){
    g_letter_count = 0;
    mp_for<1,1001>()();
    REQUIRE(g_letter_count == 21124);
  }
