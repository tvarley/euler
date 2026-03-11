// https://projecteuler.net/problem=33

/*

Digit Cancelling Fractions

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

Answer: 100

*/

package main

import "fmt"

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	num := 1
	den := 1
	for a := 1; a < 10; a++ {
		for b := 1; b < 10; b++ {
			for c := 1; c < 10; c++ {
				if a == c {
					continue
				}
				num1 := 10*a + b
				den1 := 10*b + c
				if num1 >= den1 {
					continue
				}
				if num1*c == den1*a {
					num *= a
					den *= c
				}
			}
		}
	}
	g := gcd(num, den)
	fmt.Println(den / g)
}