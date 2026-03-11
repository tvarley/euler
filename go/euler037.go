// https://projecteuler.net/problem=37

/*

Truncatable Primes

The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

Answer: 748317

*/

package main

import "fmt"

import "strconv"

func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func isTruncatable(p int) bool {
	s := strconv.Itoa(p)
	// left to right
	for i := 1; i < len(s); i++ {
		left, _ := strconv.Atoi(s[i:])
		if !isPrime(left) {
			return false
		}
	}
	// right to left
	for i := len(s) - 1; i > 0; i-- {
		right, _ := strconv.Atoi(s[:i])
		if !isPrime(right) {
			return false
		}
	}
	return true
}

func main() {
	sum := 0
	count := 0
	n := 11
	for count < 11 {
		if isPrime(n) && isTruncatable(n) {
			sum += n
			count++
		}
		n += 2
	}
	fmt.Println(sum)
}