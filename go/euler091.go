// https://projecteuler.net/problem=91

// Right Triangles with Integer Coordinates

// The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.

// There are exactly fourteen triangles containing a right angle that can be formed when each co-ordinate lies between 0 and 2 inclusive; we shall call these "obtuse" triangles instead.

// How many "right triangles" can be formed with integer co-ordinates no greater than N=50?

// Answer: 14234

// Execution time: ~100ms

// Optimizations: Brute force over all point pairs

// Interesting notes: AI-generated solution counting right triangles at origin

package main

import (
	"fmt"
)

func rightTriangles() int {
	N := 50
	count := 0
	for x1 := 0; x1 <= N; x1++ {
		for y1 := 0; y1 <= N; y1++ {
			if x1 == 0 && y1 == 0 {
				continue
			}
			for x2 := 0; x2 <= N; x2++ {
				for y2 := 0; y2 <= N; y2++ {
					if x2 == 0 && y2 == 0 {
						continue
					}
					if x1 == x2 && y1 == y2 {
						continue
					}
					if x1*x2+y1*y2 == 0 || // right at O
						-x1*(x2-x1)-y1*(y2-y1) == 0 || // right at P
						-x2*(x1-x2)-y2*(y1-y2) == 0 { // right at Q
						count++
					}
				}
			}
		}
	}
	return count / 2
}

func main() {
	fmt.Println(rightTriangles())
}