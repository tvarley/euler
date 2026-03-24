// https://projecteuler.net/problem=75

// Singular integer right triangles

// It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.
// 12 cm: (3,4,5)
// 24 cm: (6,8,10)
// 30 cm: (5,12,13)
// 36 cm: (9,12,15)
// 40 cm: (8,15,16)
// 48 cm: (12,16,20)
// In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.
// 120 cm: (30,40,50), (20,48,52), (24,45,51)
// Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?

// Answer: 161667

// Execution time: ~10000ms on modern hardware

// Optimizations: Generate primitive triples and multiples
// Interesting notes: AI-generated solution using triple generation

package main

import (
	"fmt"
)

func singularIntegerRightTriangles() int {
	limit := 1500000
	count := make([]int, limit+1)
	m := 2
	for m*m*2 <= limit {
		for n := 1; n < m; n++ {
			if (m-n)%2 == 1 && gcd(m, n) == 1 {
				a := m*m - n*n
				b := 2 * m * n
				c := m*m + n*n
				perimeter := a + b + c
				k := 1
				for k*perimeter <= limit {
					count[k*perimeter]++
					k++
				}
			}
		}
		m++
	}
	result := 0
	for _, v := range count {
		if v == 1 {
			result++
		}
	}
	return result
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	fmt.Println(singularIntegerRightTriangles())
}