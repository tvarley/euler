// https://projecteuler.net/problem=60
//
// Prime Pair Sets
//
// The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
// Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
//
// Answer: 26033

package main

import (
	"fmt"
	"strconv"
)

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

func checkPair(a, b int) bool {
	ab, _ := strconv.Atoi(fmt.Sprintf("%d%d", a, b))
	ba, _ := strconv.Atoi(fmt.Sprintf("%d%d", b, a))
	return isPrime(ab) && isPrime(ba)
}

func main() {
	primes := []int{}
	for i := 2; i < 10000; i++ {
		if isPrime(i) {
			primes = append(primes, i)
		}
	}
	minSum := 1 << 30
	for i := 0; i < len(primes); i++ {
		p1 := primes[i]
		for j := i + 1; j < len(primes); j++ {
			p2 := primes[j]
			if !checkPair(p1, p2) {
				continue
			}
			for k := j + 1; k < len(primes); k++ {
				p3 := primes[k]
				if !checkPair(p1, p3) || !checkPair(p2, p3) {
					continue
				}
				for l := k + 1; l < len(primes); l++ {
					p4 := primes[l]
					if !checkPair(p1, p4) || !checkPair(p2, p4) || !checkPair(p3, p4) {
						continue
					}
					for m := l + 1; m < len(primes); m++ {
						p5 := primes[m]
						if checkPair(p1, p5) && checkPair(p2, p5) && checkPair(p3, p5) && checkPair(p4, p5) {
							sum := p1 + p2 + p3 + p4 + p5
							if sum < minSum {
								minSum = sum
							}
						}
					}
				}
			}
		}
	}
	fmt.Println(minSum)
}