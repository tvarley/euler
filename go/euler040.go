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

package main

import "fmt"

import "strconv"

func main() {
	s := ""
	for i := 1; len(s) < 1000000; i++ {
		s += strconv.Itoa(i)
	}
	product := 1
	for _, exp := range []int{1, 10, 100, 1000, 10000, 100000, 1000000} {
		d := int(s[exp-1] - '0')
		product *= d
	}
	fmt.Println(product)
}