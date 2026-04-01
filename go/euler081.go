// https://projecteuler.net/problem=81

// Path Sum: Two Ways

// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.

// Find the minimal path sum from the top left to the bottom right by only moving right and down in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.

// Answer: 427337

// Execution time: ~0ms

// Optimizations: Dynamic programming for path finding

// Interesting notes: AI-generated solution using DP on grid

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func pathSumTwoWays() int {
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
	size := len(matrix)
	dp := make([][]int, size)
	for i := range dp {
		dp[i] = make([]int, size)
		for j := range dp[i] {
			dp[i][j] = math.MaxInt32
		}
	}
	dp[0][0] = matrix[0][0]
	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			if i > 0 {
				dp[i][j] = min(dp[i][j], dp[i-1][j]+matrix[i][j])
			}
			if j > 0 {
				dp[i][j] = min(dp[i][j], dp[i][j-1]+matrix[i][j])
			}
		}
	}
	return dp[size-1][size-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	fmt.Println(pathSumTwoWays())
}