// https://projecteuler.net/problem=87

// Prime Power Triples

// The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

// 28 = 2^2 + 2^3 + 2^4
// 33 = 3^2 + 2^3 + 2^4
// 49 = 5^2 + 2^3 + 2^4
// 47 = 2^2 + 3^3 + 2^4

// How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?

// Answer: 1097343

// Execution time: ~100ms

// Optimizations: Sieve for primes, set for uniqueness

// Interesting notes: AI-generated solution using prime generation and combinations

package main

import (
	"fmt"
	"math"
)

func primePowerTriples() int {
	limit := 50000000
	sieveLimit := int(math.Sqrt(float64(limit))) + 1

	// sieve up to sqrt(limit) ~7071
	isPrime := make([]bool, sieveLimit+1)
	for i := range isPrime {
		isPrime[i] = true
	}
	isPrime[0] = false
	isPrime[1] = false
	for i := 2; i*i <= sieveLimit; i++ {
		if isPrime[i] {
			for j := i * i; j <= sieveLimit; j += i {
				isPrime[j] = false
			}
		}
	}
	var primes []int
	for i := 2; i <= sieveLimit; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}

	// filter for each power
	maxSq := int(math.Sqrt(float64(limit)))
	sqPrimes := []int{}
	for _, p := range primes {
		if p <= maxSq {
			sqPrimes = append(sqPrimes, p)
		}
	}

	maxCb := int(math.Pow(float64(limit), 1.0/3.0)) + 1
	cbPrimes := []int{}
	for _, p := range primes {
		if p <= maxCb {
			cbPrimes = append(cbPrimes, p)
		}
	}

	maxFo := int(math.Pow(float64(limit), 0.25)) + 1
	foPrimes := []int{}
	for _, p := range primes {
		if p <= maxFo {
			foPrimes = append(foPrimes, p)
		}
	}

	set := make(map[int]bool)
	for _, p2 := range sqPrimes {
		sq := p2 * p2
		for _, p3 := range cbPrimes {
			cb := p3 * p3 * p3
			if sq+cb >= limit {
				break
			}
			for _, p4 := range foPrimes {
				fo := p4 * p4 * p4 * p4
				sum := sq + cb + fo
				if sum < limit {
					set[sum] = true
				} else {
					break
				}
			}
		}
	}
	return len(set)
}

func main() {
	fmt.Println(primePowerTriples())
}