int xor_decryption();

TEST_CASE("Prob059 Answer", "[Prob059]"){
    REQUIRE(xor_decryption() == 129448);
}