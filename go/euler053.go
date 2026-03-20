// https://projecteuler.net/problem=53
//
// Combinatoric Selections
//
// There are exactly ten ways of selecting three from five, 12345: 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
// In combinatorics, we use the notation, \binom 5 3 = 10.
// In general, \binom n r = \dfrac{n!}{r!(n-r)!}, where r \le n, n! = n \times (n-1) \times ... \times 3 \times 2 \times 1, and 0! = 1.
// It is not until n = 23, that a value exceeds one-million: \binom {23} {10} = 1144066.
// How many, not necessarily distinct, values of \binom n r for 1 \le n \le 100, are greater than one-million?
//
// Answer: 4075

package main

import (
	"fmt"
	"math/big"
)

func binomial(n, k int) *big.Int {
	if k > n-k {
		k = n - k
	}
	res := big.NewInt(1)
	for i := 0; i < k; i++ {
		res.Mul(res, big.NewInt(int64(n-i)))
		res.Div(res, big.NewInt(int64(i+1)))
	}
	return res
}

func main() {
	count := 0
	limit := big.NewInt(1000000)
	for n := 1; n <= 100; n++ {
		for r := 0; r <= n; r++ {
			if binomial(n, r).Cmp(limit) > 0 {
				count++
			}
		}
	}
	fmt.Println(count)
}