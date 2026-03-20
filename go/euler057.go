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
	h := big.NewInt(1)
	k := big.NewInt(1)
	for i := 1; i <= 1000; i++ {
		hNext := new(big.Int).Mul(h, big.NewInt(2))
		hNext.Add(hNext, k)
		kNext := new(big.Int).Mul(k, big.NewInt(2))
		kNext.Add(kNext, h)
		h = hNext
		k = kNext
		if len(h.String()) > len(k.String()) {
			count++
		}
	}
	fmt.Println(count)
}