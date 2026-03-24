#include "euler065.cpp"
TEST_CASE("Convergents of e") {
    REQUIRE(convergents_of_e() == 272);
}