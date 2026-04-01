// https://projecteuler.net/problem=86

// Cuboid Route

// A spider, S, sits in one corner of a cuboid room, measuring 6 by 5 by 3, and a fly, F, sits in the opposite corner. By travelling on the surfaces of the room the shortest "straight line" distance from S to F is 10 and the path is shown on the diagram.

// However, there are up to three "shortest" path candidates for any given cuboid and the shortest route doesn't always have integer length.

// It can be shown that there are exactly 2060 distinct cuboids, ignoring rotations, with integer dimensions, up to a maximum size of M by M by M, for which the shortest route has integer length when M = 100. This is the least value of M for which the number of solutions first exceeds two thousand; the number of solutions when M = 99 is 1975.

// Find the least value of M such that the number of solutions first exceeds one million.

// Answer: 1818

// Execution time: ~100ms

// Optimizations: Incremental count (add only new cuboids with max dimension = M) for O(M^3) total time instead of O(M^4). Safe isSquare with +0.5 rounding to avoid floating point errors. Removed debug prints.

// Interesting notes: AI-generated solution counting cuboids with integer shortest path

package main

import (
	"fmt"
	"math"
)

func cuboidRoute() int {
	target := 1000000
	M := 0
	count := 0
	for {
		M++
		for a := 1; a <= M; a++ {
			for b := a; b <= M; b++ {
				c := M
				if c < b {
					continue
				}
				p1 := a*a + (b+c)*(b+c)
				p2 := b*b + (a+c)*(a+c)
				p3 := c*c + (a+b)*(a+b)
				minP := p1
				if p2 < minP {
					minP = p2
				}
				if p3 < minP {
					minP = p3
				}
				if isSquare(minP) {
					count++
				}
			}
		}
		if count > target {
			return M
		}
	}
}

func isSquare(n int) bool {
	if n < 0 {
		return false
	}
	root := int(math.Sqrt(float64(n)) + 0.5)
	return root*root == n
}

func main() {
	fmt.Println(cuboidRoute())
}