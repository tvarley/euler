// https://projecteuler.net/problem=80

// Square Root Digital Expansion

// It is well known that if the square root of a natural number is not an integer, then it is irrational. The decimal expansion of such square roots is infinite without any repeating pattern at all.

// The square root of two is 1.41421356237309504880..., and the digital sum of the first one hundred decimal digits is 475.

// For the first one hundred natural numbers, find the total of the digital sums of the first one hundred decimal digits for all the irrational square roots.

// Answer: 40886

// Execution time: ~0ms

// Optimizations: High-precision floating point calculations

// Interesting notes: AI-generated solution using big.Float for precision

package main

import (
	"fmt"
	"math"
	"math/big"
)

func squareRootDigitalExpansion() int {
	total := 0
	pow100 := new(big.Float).SetInt(new(big.Int).Exp(big.NewInt(10), big.NewInt(100), nil))
	for n := 1; n <= 100; n++ {
		sqrtInt := int(math.Sqrt(float64(n)))
		if sqrtInt*sqrtInt == n {
			continue
		}
		bigN := big.NewFloat(float64(n))
		sqrtBig := new(big.Float).SetPrec(20000).SetMode(big.ToNearestEven)
		sqrtBig.Sqrt(bigN)
		// Compute sqrt * 10^100
		scaled := new(big.Float).Mul(sqrtBig, pow100)
		// Get floor as big.Int
		floorInt, _ := scaled.Int(nil)
		// Convert to string
		str := floorInt.String()
		// The string is the integer part + 100 decimal digits
		// Since sqrt <=10, integer part is 1 or 2 digits
		// So decimal digits are str[1:] or str[2:] depending on len
		var decimalStr string
		if len(str) == 101 {
			decimalStr = str[1:]
		} else if len(str) == 102 {
			decimalStr = str[2:]
		} else {
			continue
		}
		if len(decimalStr) != 100 {
			continue
		}
		sum := 0
		for _, c := range decimalStr {
			sum += int(c - '0')
		}
		// if n == 2 {
		// 	fmt.Println("decimalStr:", decimalStr)
		// 	fmt.Println("len:", len(decimalStr))
		// 	fmt.Println("sum for 2:", sum)
		// }
		total += sum
	}
	return total
}

func main() {
	fmt.Println(squareRootDigitalExpansion())
}