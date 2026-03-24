// https://projecteuler.net/problem=67

// Maximum path sum II

// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
// 3
// 7 4
// 2 4 6
// 8 5 9 3
// That is, 3 + 7 + 4 + 9 = 23.
// Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...), a 15K text file containing a triangle with one-hundred rows.

// Answer: 7273

// Execution time: ~0ms on modern hardware

// Optimizations: Dynamic programming from bottom up, reusing rows to save space
// Interesting notes: AI-generated solution reading triangle data and computing maximum path sum

package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func maximumPathSumII() int {
	content, _ := os.ReadFile("euler_67_data.txt")
	lines := strings.Split(string(content), "\n")
	triangle := make([][]int, 0)
	for _, line := range lines {
		if line == "" {
			continue
		}
		parts := strings.Fields(line)
		row := make([]int, len(parts))
		for i, p := range parts {
			row[i], _ = strconv.Atoi(p)
		}
		triangle = append(triangle, row)
	}
	for row := len(triangle) - 2; row >= 0; row-- {
		for col := 0; col < len(triangle[row]); col++ {
			triangle[row][col] += max(triangle[row+1][col], triangle[row+1][col+1])
		}
	}
	return triangle[0][0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(maximumPathSumII())
}