// https://projecteuler.net/problem=46

/*

Goldbach's Other Conjecture

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×1²
15 = 7 + 2×2²
21 = 3 + 2×3²
25 = 7 + 2×3²
27 = 19 + 2×2²
33 = 31 + 2×1²

It turns out that the conjecture was false. What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

Answer: 5777

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
	for i := 2; i < 10000; i++ {
		if isPrime(i) {
			primes = append(primes, i)
		}
	}
	for n := 9; ; n += 2 {
		if isPrime(n) {
			continue
		}
		found := false
		for _, p := range primes {
			if p >= n {
				break
			}
			rem := n - p
			if rem%2 == 0 {
				sq := rem / 2
				k := 1
				for k*k < sq {
					k++
				}
				if k*k == sq {
					found = true
					break
				}
			}
		}
		if !found {
			fmt.Println(n)
			return
		}
	}
}