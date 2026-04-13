// https://projecteuler.net/problem=76

// Counting summations

// It is possible to write five as a sum in exactly six different ways:

// 4 + 1
// 3 + 2
// 3 + 1 + 1
// 2 + 3
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 4
// 1 + 3 + 1
// 1 + 2 + 2
// 1 + 2 + 1 + 1
// 1 + 1 + 3
// 1 + 1 + 2 + 1
// 1 + 1 + 1 + 2
// 1 + 1 + 1 + 1 + 1

// How many different ways can one hundred be written as a sum of at least two positive integers?

// Answer: 190569291

// Execution time: ~1ms on modern hardware

// Optimizations: Dynamic programming for partition function
// Interesting notes: Subtract 1 from p(100) to exclude the single number case

package main

import (
	"fmt"
)

func countingSummations() int {
	const n = 100
	dp := make([]int, n+1)
	dp[0] = 1
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			dp[j] += dp[j-i]
		}
	}
	return dp[n] - 1
}

func main() {
	fmt.Println(countingSummations())
}