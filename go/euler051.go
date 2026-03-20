// https://projecteuler.net/problem=51
//
// Prime Digit Replacements
//
// By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
// By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
// Consequently 56003, being the first member of this family, is the smallest prime with this property.
// Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
//
// Answer: 121313

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
	for _, p := range primes {
		if p < 100000 {
			continue
		}
		s := fmt.Sprintf("%d", p)
		digits := []byte(s)
		for mask := 1; mask < (1<<len(digits))-1; mask++ {
			family := []int{}
			for d := 0; d < 10; d++ {
				if d == 0 && (mask&1) != 0 {
					continue
				}
				num := 0
				for i, digit := range digits {
					if (mask&(1<<uint(i))) != 0 {
						num = num*10 + d
					} else {
						num = num*10 + int(digit-'0')
					}
				}
				if isPrime(num) {
					family = append(family, num)
				}
			}
			if len(family) == 8 {
				fmt.Println(family[0])
				return
			}
		}
	}
}