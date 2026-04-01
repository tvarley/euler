// https://projecteuler.net/problem=77

// Prime Summations

// It is possible to write ten as the sum of primes in exactly five different ways:

// 7 + 3
// 5 + 5
// 5 + 3 + 2
// 3 + 3 + 2 + 2
// 2 + 2 + 2 + 2 + 2

// What is the first value which can be written as the sum of primes in over five thousand different ways?

// Answer: 71

// Execution time: ~0ms

// Optimizations: Sieve for primes, DP for prime partitions

// Interesting notes: AI-generated solution using prime generation and DP

package main

import (
	"fmt"
)

func primeSummations() int {
	limit := 1000
	isPrime := make([]bool, limit+1)
	for i := range isPrime {
		isPrime[i] = true
	}
	isPrime[0], isPrime[1] = false, false
	for i := 2; i*i <= limit; i++ {
		if isPrime[i] {
			for j := i * i; j <= limit; j += i {
				isPrime[j] = false
			}
		}
	}
	primes := []int{}
	for i := 2; i <= limit; i++ {
		if isPrime[i] {
			primes = append(primes, i)
		}
	}
	n := 2
	for {
		ways := 0
		dp := make([]int, n+1)
		dp[0] = 1
		for _, p := range primes {
			if p > n {
				break
			}
			for j := p; j <= n; j++ {
				dp[j] += dp[j-p]
			}
		}
		ways = dp[n]
		if ways > 5000 {
			return n
		}
		n++
	}
}

func main() {
	fmt.Println(primeSummations())
}