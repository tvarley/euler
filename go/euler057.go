// https://projecteuler.net/problem=57
//
// Square Root Convergents
//
// It is possible to show that the square root of two can be expressed as an infinite continued fraction.
// √2 =1+ 1/(2+ 1/(2 +1/(2+ ...)))
// By expanding this for the first four iterations, we get:
// 1 + 1/2 = 3/2 = 1.5
// 1 + 1/(2 + 1/2) = 7/5 = 1.4
// 1 + 1/(2 + 1/(2+1/2)) = 17/12 = 1.41666...
// 1 + 1/(2 + 1/(2+1/(2+1/2))) = 41/29 = 1.41379...
// The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
// In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?
//
// Answer: 153

package main

import (
	"fmt"
	"math/big"
)

func main() {
	count := 0
	h_prev := big.NewInt(1)
	k_prev := big.NewInt(1)
	h_curr := big.NewInt(3)
	k_curr := big.NewInt(2)
	if len(h_curr.String()) > len(k_curr.String()) {
		count++
	}
	for i := 2; i <= 1000; i++ {
		h_next := new(big.Int).Mul(h_curr, big.NewInt(2))
		h_next.Add(h_next, h_prev)
		k_next := new(big.Int).Mul(k_curr, big.NewInt(2))
		k_next.Add(k_next, k_prev)
		h_prev = h_curr
		k_prev = k_curr
		h_curr = h_next
		k_curr = k_next
		if len(h_curr.String()) > len(k_curr.String()) {
			count++
		}
	}
	fmt.Println(count)
}