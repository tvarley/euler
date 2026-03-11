// https://projecteuler.net/problem=35

/*

Circular Primes

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

Answer: 55

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

func rotations(s string) []string {
	res := []string{}
	for i := 0; i < len(s); i++ {
		res = append(res, s[i:]+s[:i])
	}
	return res
}

func main() {
	count := 0
	for n := 2; n < 1000000; n++ {
		if !isPrime(n) {
			continue
		}
		s := strconv.Itoa(n)
		allPrime := true
		for _, rot := range rotations(s) {
			r, _ := strconv.Atoi(rot)
			if !isPrime(r) {
				allPrime = false
				break
			}
		}
		if allPrime {
			count++
		}
	}
	fmt.Println(count)
}