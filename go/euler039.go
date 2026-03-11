// https://projecteuler.net/problem=39

/*

Integer Right Triangles

If p is the perimeter of a right angle triangle with integral length sides, {a, b, c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

Answer: 840

*/

package main

import "fmt"

func main() {
	maxCount := 0
	maxP := 0
	for p := 1; p <= 1000; p++ {
		count := 0
		for a := 1; a < p; a++ {
			for b := a; b < p-a; b++ {
				c := p - a - b
				if a*a + b*b == c*c {
					count++
				}
			}
		}
		if count > maxCount {
			maxCount = count
			maxP = p
		}
	}
	fmt.Println(maxP)
}