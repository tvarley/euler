// https://projecteuler.net/problem=50

/*

Consecutive Prime Sum

The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13.

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

Answer: 997651

*/

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
	primes := []int{}
	for i := 2; i < 1000000; i++ {
		if isPrime(i) {
			primes = append(primes, i)
		}
	}
	maxLen := 0
	maxPrime := 0
	for start := 0; start < len(primes); start++ {
		sum := 0
		for end := start; end < len(primes); end++ {
			sum += primes[end]
			if sum >= 1000000 {
				break
			}
			if isPrime(sum) && end-start+1 > maxLen {
				maxLen = end - start + 1
				maxPrime = sum
			}
		}
	}
	fmt.Println(maxPrime)
}