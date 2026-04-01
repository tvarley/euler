// https://projecteuler.net/problem=96

// Su Doku

// Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares. The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column, and 3 by 3 box contains each of the digits 1 to 9. Below is an example of a typical starting puzzle grid and its solution grid.

// A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may require "guessing" when the solver is confronted with a problem that cannot be solved by logic alone.

// The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions (the first puzzle in the file is the example above).

// By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid; for example, 483 is the 3-digit number found in the top left corner of the solution grid above.

// Answer: 24702

// Execution time: ~200ms

// Optimizations: Backtracking solver with validity checks

// Interesting notes: AI-generated solution solving 50 Sudoku puzzles

package main

import (
	"bufio"
	"fmt"
	"os"
)

func isValid(grid [][]int, row, col, num int) bool {
	for i := 0; i < 9; i++ {
		if grid[row][i] == num || grid[i][col] == num {
			return false
		}
	}
	boxRow := (row / 3) * 3
	boxCol := (col / 3) * 3
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if grid[boxRow+i][boxCol+j] == num {
				return false
			}
		}
	}
	return true
}

func solve(grid [][]int) bool {
	for row := 0; row < 9; row++ {
		for col := 0; col < 9; col++ {
			if grid[row][col] == 0 {
				for num := 1; num <= 9; num++ {
					if isValid(grid, row, col, num) {
						grid[row][col] = num
						if solve(grid) {
							return true
						}
						grid[row][col] = 0
					}
				}
				return false
			}
		}
	}
	return true
}

func suDoku() int {
	file, err := os.Open("p096_sudoku.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	sum := 0
	for scanner.Scan() {
		line := scanner.Text()
		if len(line) >= 4 && line[:4] == "Grid" {
			continue
		}
		grid := make([][]int, 9)
		for i := range grid {
			grid[i] = make([]int, 9)
		}
		// Parse first line
		for j := 0; j < 9; j++ {
			grid[0][j] = int(line[j] - '0')
		}
		// Read remaining 8 lines
		for i := 1; i < 9; i++ {
			scanner.Scan()
			line = scanner.Text()
			for j := 0; j < 9; j++ {
				grid[i][j] = int(line[j] - '0')
			}
		}
		solve(grid)
		num := grid[0][0]*100 + grid[0][1]*10 + grid[0][2]
		sum += num
	}
	return sum
}

func main() {
	fmt.Println(suDoku())
}