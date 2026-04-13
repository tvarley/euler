// https://projecteuler.net/problem=95

// Amicable Chains

// The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As the sum of these divisors is equal to 28, we call it a perfect number.

// Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper divisors of 284 is 220, forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.

// Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:

// 12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → …)

// Since this chain returns to its starting point, it is called an amicable chain.

// Find the smallest member of the longest amicable chain with no element exceeding one million.

// Answer: 14316

// Execution time: ~500ms

// Optimizations: Precomputed divisor sums with sieve method

// Interesting notes: AI-generated solution using cycle detection in divisor sum chains

package main

import (
	"fmt"
)

const MAX = 1000000

func amicableChains() int {
	sumDiv := make([]int, MAX+1)
	for i := 1; i <= MAX; i++ {
		for j := i * 2; j <= MAX; j += i {
			sumDiv[j] += i
		}
	}

	maxLength := 0
	minMember := MAX
	visited := make([]bool, MAX+1)

	for i := 2; i <= MAX; i++ {
		if visited[i] || sumDiv[i] > MAX {
			continue
		}

		chain := []int{}
		chainSet := make(map[int]bool)
		current := i

		for current <= MAX && sumDiv[current] != current && !chainSet[current] {
			chain = append(chain, current)
			chainSet[current] = true
			current = sumDiv[current]
		}

		// Check if we found a cycle
		if chainSet[current] && len(chain) > 1 {
			// Find where the cycle starts
			cycleStart := -1
			for j, val := range chain {
				if val == current {
					cycleStart = j
					break
				}
			}
			cycleLength := len(chain) - cycleStart

			if cycleLength > maxLength {
				maxLength = cycleLength
				// Find smallest member in the cycle
				smallest := MAX
				for j := cycleStart; j < len(chain); j++ {
					if chain[j] < smallest {
						smallest = chain[j]
					}
					visited[chain[j]] = true
				}
				minMember = smallest
			}
		}
	}

	return minMember
}

func main() {
	fmt.Println(amicableChains())
}