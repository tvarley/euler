// https://projecteuler.net/problem=97

// Large Non-Mersenne Prime

// The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593−1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p−1, have been found which contain more digits.

// However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^7830457+1.

// Find the last ten digits of this prime number.

// Answer: 8739992577

// Execution time: ~0ms

// Optimizations: Modular exponentiation using big integers

// Interesting notes: AI-generated solution using Go's big.Int for large number arithmetic

package main

import (
	"fmt"
	"math/big"
)

func largeNonMersennePrime() string {
	mod := big.NewInt(10000000000) // 10^10
	base := big.NewInt(2)
	exp := big.NewInt(7830457)
	pow2 := new(big.Int).Exp(base, exp, mod)
	result := new(big.Int).Mul(big.NewInt(28433), pow2)
	result.Add(result, big.NewInt(1))
	result.Mod(result, mod)
	return result.String()
}

func main() {
	fmt.Println(largeNonMersennePrime())
}