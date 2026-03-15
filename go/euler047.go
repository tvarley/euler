// https://projecteuler.net/problem=47

/*

Distinct Primes Factors

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5.

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?

Answer: 134043

*/

package main

import "fmt"

func primeFactors(n int) map[int]int {
	factors := make(map[int]int)
	for i := 2; i*i <= n; i++ {
		for n%i == 0 {
			factors[i]++
			n /= i
		}
	}
	if n > 1 {
		factors[n]++
	}
	return factors
}

func main() {
	n := 2
	for {
		if len(primeFactors(n)) == 4 && len(primeFactors(n+1)) == 4 && len(primeFactors(n+2)) == 4 && len(primeFactors(n+3)) == 4 {
			fmt.Println(n)
			return
		}
		n++
	}
}