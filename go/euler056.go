// https://projecteuler.net/problem=56
//
// Powerful Digit Sum
//
// A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
// Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
//
// Answer: 972

package main

import (
	"fmt"
	"math/big"
	"strconv"
)

func main() {
	maxSum := 0
	for a := 2; a < 100; a++ {
		for b := 2; b < 100; b++ {
			num := big.NewInt(int64(a))
			num.Exp(num, big.NewInt(int64(b)), nil)
			sum := 0
			for _, r := range num.String() {
				d, _ := strconv.Atoi(string(r))
				sum += d
			}
			if sum > maxSum {
				maxSum = sum
			}
		}
	}
	fmt.Println(maxSum)
}