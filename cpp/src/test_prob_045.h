#include "euler045.cpp"

TEST_CASE("Prob045 Answer", "[Prob045]"){
    REQUIRE(triangular_pentagonal_hexagonal() == 1533776805);
}