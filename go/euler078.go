// https://projecteuler.net/problem=78

// Coin Partitions

// Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

// Find the least value of n for which p(n) is divisible by one million.

// Answer: 55374

// Execution time: ~100ms

// Optimizations: Pentagonal number theorem with modulo computation for O(n^{1.5}) time complexity

// Interesting notes: AI-generated solution using big.Int for large numbers

package main

import (
	"fmt"
)

func coinPartitions() int {
	const MOD = 1000000
	const LIMIT = 60000
	p := make([]int, LIMIT+1)
	p[0] = 1
	for n := 1; n <= LIMIT; n++ {
		sum := 0
		i := 1
		for {
			g1 := i * (3*i - 1) / 2
			if g1 > n {
				break
			}
			sign := 1
			if i%2 == 0 {
				sign = -1
			}
			sum = (sum + sign*p[n-g1]) % MOD
			if sum < 0 {
				sum += MOD
			}
			g2 := i * (3*i + 1) / 2
			if g2 > n {
				break
			}
			sum = (sum + sign*p[n-g2]) % MOD
			if sum < 0 {
				sum += MOD
			}
			i++
		}
		p[n] = sum
		if p[n] == 0 {
			return n
		}
	}
	return -1 // not found
}


func main() {
	fmt.Println(coinPartitions())
}
