// https://projecteuler.net/problem=73

// Counting fractions in a range

// Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
// If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:
// 1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
// It can be seen that there are 3 fractions between 1/3 and 1/2.
// How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ≤ 12,000?

// Answer: 7295372

// Execution time: ~1000ms on modern hardware

// Optimizations: Loop over d, count n with gcd
// Interesting notes: AI-generated solution counting fractions in (1/3,1/2)

package main

import (
	"fmt"
)

func countingFractionsInARange() int {
	limit := 12000
	count := 0
	for d := 5; d <= limit; d++ {
		minN := (d / 3) + 1
		maxN := d / 2
		for n := minN; n <= maxN; n++ {
			if gcd(n, d) == 1 {
				count++
			}
		}
	}
	return count
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	fmt.Println(countingFractionsInARange())
}