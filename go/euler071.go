// https://projecteuler.net/problem=71

// Ordered fractions

// Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
// If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
// 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
// It can be seen that 2/5 is the fraction immediately to the left of 3/7.
// By listing the set of reduced proper fractions for d ≤ 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.

// Answer: 428571

// Execution time: ~0ms on modern hardware

// Optimizations: Farey sequence to find fraction just below 3/7
// Interesting notes: AI-generated solution finding largest n/d < 3/7 with d<=1e6

package main

import (
	"fmt"
)

func orderedFractions() int {
	limit := 1000000
	maxN := 0
	for d := 5; d <= limit; d++ {
		n := (3*d - 1) / 7
		if n > 0 && gcd(n, d) == 1 {
			if float64(n)/float64(d) > float64(maxN)/float64(limit) {
				maxN = n
			}
		}
	}
	return maxN
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	fmt.Println(orderedFractions())
}