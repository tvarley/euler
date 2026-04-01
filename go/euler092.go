// https://projecteuler.net/problem=92

// Square Digit Chains

// A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

// For example,

// 44 → 32 → 13 → 10 → 1 → 1
// 85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89 → ...

// Therefore any chain that arrives at 1 or 4 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 4.

// How many starting numbers below ten million will arrive at 4?

// Answer: 8581146

// Execution time: ~2000ms

// Optimizations: Precompute results for small numbers

// Interesting notes: AI-generated solution using memoization for digit square sums

package main

import (
	"fmt"
)

func squareDigitChains() int {
	limit := 10000000
	maxSum := 7 * 81 // 567
	memo := make([]int, maxSum+1) // 0 not computed, 1 leads to 1, 2 leads to 89
	memo[1] = 1
	memo[89] = 2

	var getChainEnd func(int) int
	getChainEnd = func(n int) int {
		if n == 1 || n == 89 {
			return memo[n]
		}
		if memo[n] != 0 {
			return memo[n]
		}
		memo[n] = getChainEnd(digitSquareSum(n))
		return memo[n]
	}

	count := 0
	for i := 1; i < limit; i++ {
		if getChainEnd(digitSquareSum(i)) == 2 {
			count++
		}
	}
	return count
}

func digitSquareSum(n int) int {
	sum := 0
	for n > 0 {
		d := n % 10
		sum += d * d
		n /= 10
	}
	return sum
}

func main() {
	fmt.Println(squareDigitChains())
}