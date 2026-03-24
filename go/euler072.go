// https://projecteuler.net/problem=72

// Counting fractions

// Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
// If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
// 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
// It can be seen that there are 21 elements in this set.
// How many elements would be contained in the set of reduced proper fractions for d ≤ 1,000,000?

// Answer: 303963552391

// Execution time: ~1000ms on modern hardware

// Optimizations: Euler's totient function sieve
// Interesting notes: AI-generated solution using phi function to count fractions

package main

import (
	"fmt"
)

func countingFractions() int {
	limit := 1000000
	phi := make([]int, limit+1)
	for i := range phi {
		phi[i] = i
	}
	for i := 2; i <= limit; i++ {
		if phi[i] == i {
			for j := i; j <= limit; j += i {
				phi[j] = phi[j] / i * (i - 1)
			}
		}
	}
	sum := 0
	for i := 2; i <= limit; i++ {
		sum += phi[i]
	}
	return sum
}

func main() {
	fmt.Println(countingFractions())
}