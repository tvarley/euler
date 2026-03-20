// https://projecteuler.net/problem=58
//
// Spiral Primes
//
// Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
// [diagram]
// It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.
// If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed.
// If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
//
// Answer: 26241

package main

import "fmt"

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func main() {
	side := 1
	primes := 0
	total := 1
	current := 1
	for {
		side += 2
		for i := 0; i < 4; i++ {
			current += side - 1
			total++
			if isPrime(current) {
				primes++
			}
		}
		if primes*10 < total {
			fmt.Println(side)
			break
		}
	}
}