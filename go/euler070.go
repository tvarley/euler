// https://projecteuler.net/problem=70

// Totient permutation

// Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n that are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
// The number 87109 has a special property; it is a permutation of 79180, the value of φ(87109). In other words, 87109 is a permutation of 79180.
// Find the value of n, 1 < n < 10^7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.

// Answer: 8319823

// Execution time: ~1000ms on modern hardware

// Optimizations: Precompute primes, sieve for phi, check digit permutations
// Interesting notes: AI-generated solution using prime sieve and digit sorting for permutation check

package main

import (
	"fmt"
	"sort"
	"strconv"
)

func totientPermutation() int {
	limit := 10000000
	phi := make([]int, limit)
	for i := range phi {
		phi[i] = i
	}
	for i := 2; i < limit; i++ {
		if phi[i] == i { // prime
			for j := i; j < limit; j += i {
				phi[j] = phi[j] / i * (i - 1)
			}
		}
	}
	minRatio := float64(100)
	result := 0
	for n := 2; n < limit; n++ {
		p := phi[n]
		ratio := float64(n) / float64(p)
		if ratio < minRatio && isPermutation(n, p) {
			minRatio = ratio
			result = n
		}
	}
	return result
}

func isPermutation(a, b int) bool {
	sa := strconv.Itoa(a)
	sb := strconv.Itoa(b)
	if len(sa) != len(sb) {
		return false
	}
	aa := []rune(sa)
	bb := []rune(sb)
	sort.Slice(aa, func(i, j int) bool { return aa[i] < aa[j] })
	sort.Slice(bb, func(i, j int) bool { return bb[i] < bb[j] })
	return string(aa) == string(bb)
}

func main() {
	fmt.Println(totientPermutation())
}