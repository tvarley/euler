// https://projecteuler.net/problem/100

// Arranged Probability

// If a box contains twenty-one coloured discs, composed of fifteen blue discs and six red discs, and two discs were taken at random, it can be seen that the probability of taking two blue discs, P(BB) = (15/21)×(14/20) = 1/2.

// The next such arrangement, for which there is exactly 50% chance of taking two blue discs at random, is a box containing eighty-five blue discs and thirty-five red discs.

// By finding the first arrangement to contain over 10^12 = 1,000,000,000,000 discs in total, determine the number of blue discs that the box would contain.

// Answer: 756872327473

// Execution time: ~0ms

// Optimizations: Pell equation recurrence for direct solution

// Interesting notes: AI-generated solution using mathematical recurrence

package main

import (
	"fmt"
)

func arrangedProbability() int64 {
	b := int64(15)
	n := int64(21)
	for n <= 1000000000000 {
		b_new := 3*b + 2*n - 2
		n_new := 4*b + 3*n - 3
		b = b_new
		n = n_new
	}
	return b
}

func main() {
	fmt.Println(arrangedProbability())
}