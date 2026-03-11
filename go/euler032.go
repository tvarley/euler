// https://projecteuler.net/problem=32

/*

Pandigital Products

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

Answer: 45228

*/

package main

import "fmt"

import "strconv"

func isPandigital(s string) bool {
	if len(s) != 9 {
		return false
	}
	digits := make([]int, 10)
	for _, c := range s {
		if c == '0' {
			return false
		}
		d := int(c - '0')
		if digits[d] > 0 {
			return false
		}
		digits[d]++
	}
	return true
}

func main() {
	products := make(map[int]bool)
	for a := 1; a < 10000; a++ {
		for b := 1; b < 10000/a; b++ {
			c := a * b
			s := strconv.Itoa(a) + strconv.Itoa(b) + strconv.Itoa(c)
			if len(s) == 9 && isPandigital(s) {
				products[c] = true
			}
		}
	}
	sum := 0
	for p := range products {
		sum += p
	}
	fmt.Println(sum)
}