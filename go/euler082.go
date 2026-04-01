// https://projecteuler.net/problem=82

// Path Sum: Three Ways

// The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.

// Find the minimal path sum from the left column to the right column in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.

// Answer: 260324

// Execution time: ~0ms

// Optimizations: Dynamic programming with directional constraints

// Interesting notes: AI-generated solution using column-wise DP

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func pathSumThreeWays() int {
	matrix := readMatrix()
	size := len(matrix)
	dp := make([][]int, size)
	for i := range dp {
		dp[i] = make([]int, size)
		for j := range dp[i] {
			dp[i][j] = math.MaxInt32
		}
	}
	for i := 0; i < size; i++ {
		dp[i][0] = matrix[i][0]
	}
	for j := 1; j < size; j++ {
		// First, set from left
		for i := 0; i < size; i++ {
			dp[i][j] = dp[i][j-1] + matrix[i][j]
		}
		// Then, propagate up
		for i := 1; i < size; i++ {
			dp[i][j] = min(dp[i][j], dp[i-1][j] + matrix[i][j])
		}
		// Then, propagate down
		for i := size - 2; i >= 0; i-- {
			dp[i][j] = min(dp[i][j], dp[i+1][j] + matrix[i][j])
		}
	}
	minPath := math.MaxInt32
	for i := 0; i < size; i++ {
		minPath = min(minPath, dp[i][size-1])
	}
	return minPath
}

func readMatrix() [][]int {
	file, err := os.Open("matrix.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	matrix := [][]int{}
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, ",")
		row := []int{}
		for _, p := range parts {
			num, _ := strconv.Atoi(strings.TrimSpace(p))
			row = append(row, num)
		}
		matrix = append(matrix, row)
	}
	return matrix
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Println(pathSumThreeWays())
}