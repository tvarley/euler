// https://projecteuler.net/problem=40

/*

Champernowne's Constant

An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021…

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the nth digit of the fractional part, find the value of the following expression.

d₁ × d₁₀ × d₁₀₀ × d₁₀₀₀ × d₁₀₀₀₀ × d₁₀₀₀₀₀ × d₁₀₀₀₀₀₀

Answer: 210

*/

// Optimized implementation: Instead of building a massive string (O(n²) time due to immutable strings),
// directly compute each required digit using mathematical grouping of numbers by digit length.
// This reduces to O(1) per digit query with minimal memory usage.
package main

import "fmt"

import "strconv"

// getDigit returns the nth digit (1-based) in Champernowne's constant.
// Groups: 1-digit (1-9): 9 digits
//         2-digit (10-99): 180 digits
//         3-digit (100-999): 2700 digits
//         k-digit: 9*10^{k-1} numbers, contributing k*9*10^{k-1} digits
func getDigit(n int) int {
	if n <= 0 {
		return 0
	}
	cumulative := 0
	k := 1
	for {
		digitsInGroup := k * 9 * pow10(k-1)
		if cumulative + digitsInGroup >= n {
			break
		}
		cumulative += digitsInGroup
		k++
	}
	// Now in k-digit group
	digitsBefore := cumulative
	numbersBefore := pow10(k - 1)
	offset := n - digitsBefore - 1
	number := numbersBefore + offset/k
	posInNumber := offset % k
	numStr := strconv.Itoa(number)
	return int(numStr[posInNumber] - '0')
}

func pow10(exp int) int {
	result := 1
	for i := 0; i < exp; i++ {
		result *= 10
	}
	return result
}

func main() {
	product := 1
	for _, exp := range []int{1, 10, 100, 1000, 10000, 100000, 1000000} {
		d := getDigit(exp)
		product *= d
	}
	fmt.Println(product)
}