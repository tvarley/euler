// https://projecteuler.net/problem=85

// Counting Rectangles

// By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles.

// Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.

// Answer: 2772

// Execution time: ~0ms

// Optimizations: Brute force search for minimal difference

// Interesting notes: AI-generated solution using rectangle counting formula

package main

import (
	"fmt"
	"math"
)

func countingRectangles() int {
	target := 2000000
	minDiff := math.MaxInt32
	bestArea := 0
	for m := 1; m <= 1000; m++ {
		for n := 1; n <= 1000; n++ {
			rects := m * (m + 1) * n * (n + 1) / 4
			diff := abs(rects - target)
			if diff < minDiff {
				minDiff = diff
				bestArea = m * n
			}
		}
	}
	return bestArea
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	fmt.Println(countingRectangles())
}