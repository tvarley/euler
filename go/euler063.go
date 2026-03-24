// https://projecteuler.net/problem=63

// Powerful Digit Counts

// The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
// How many n-digit positive integers exist which are also an nth power?

// Answer: 49

// Execution time: ~0ms on modern hardware

// Optimizations: Mathematical logarithmic approach using log10 to compute exact count without power calculations

package main

import (
	"fmt"
	"math"
)

func powerfulDigitCounts() int {
	count := 0
	for a := 1; a <= 9; a++ {
		logA := math.Log10(float64(a))
		maxN := int(1.0 / (1.0 - logA))
		count += maxN
	}
	return count
}

func main() {
	fmt.Println(powerfulDigitCounts())
}