#include "sieve_eratos.h"

TEST_CASE("TestSieveEratos Known001", "[TestSieveEratos]"){
  CSieveOfEratosthenes sieve(2000000);
  REQUIRE(sieve.sum(10) == 17);
}

TEST_CASE("TestSieveEratos Known002", "[TestSieveEratos]"){
  CSieveOfEratosthenes sieve(2000000);
  REQUIRE(sieve.sum(2000000) == 142913828922);
}

TEST_CASE("TestSieveEratos Known003", "[TestSieveEratos]"){
  CSieveOfEratosthenes sieve(2000000);
  REQUIRE(sieve.get_nth(6) == 13);
}

TEST_CASE("TestSieveEratos Known004", "[TestSieveEratos]"){
  CSieveOfEratosthenes sieve(2000000);
  REQUIRE(sieve.get_nth(10001) == 104743);
}
