// https://projecteuler.net/problem=90

// Cube Digit Pairs

// Each of the six faces on a cube has a different digit (0 to 9) printed on it; the same is done for a second cube. By placing the two cubes side-by-side in different positions we can form a variety of 2-digit numbers.

// For example, the square number 01 can be formed by placing a 0 on the first cube and a 1 on the second; 04 can be formed with a 0 and a 4; 09 with a 0 and a 9; 16 with a 1 and a 6; 25 with a 2 and a 5 etc.

// In fact, by carefully choosing the digits on both cubes it is possible to display all of the square numbers below one-hundred: 01, 04, 09, 16, 25, 36, 49, 64, and 81.

// For example, one way this can be achieved is by placing {0, 1, 2, 3, 4, 5} on one cube and {6, 7, 8, 9} on the other, but this is not the only way.

// Find the number of distinct arrangements of the two cubes which allow for all of the above square numbers to be displayed.

// Answer: 1217

// Execution time: ~10ms

// Optimizations: Generate combinations and check conditions

// Interesting notes: AI-generated solution using set operations for digit combinations

package main

import (
	"fmt"
)

func cubeDigitPairs() int {
	// required pairs
	required := [][2]int{
		{0, 1}, {0, 4}, {0, 9}, {1, 6}, {2, 5}, {3, 6}, {4, 9}, {6, 4}, {8, 1},
	}

	// generate all possible 6-digit combinations
	allComb := generateCombinations()

	count := 0
	for i := 0; i < len(allComb); i++ {
		for j := i + 1; j < len(allComb); j++ {
			cube1 := allComb[i]
			cube2 := allComb[j]
			if canFormAll(required, cube1, cube2) {
				count++
			}
		}
	}
	return count
}

func generateCombinations() [][]bool {
	digits := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	n := len(digits)
	comb := make([][]bool, 0)
	// generate all combinations of 6 out of 10
	var generate func(start int, current []int)
	generate = func(start int, current []int) {
		if len(current) == 6 {
			has := make([]bool, 10)
			for _, d := range current {
				has[d] = true
			}
			comb = append(comb, has)
			return
		}
		for i := start; i < n; i++ {
			generate(i+1, append(current, digits[i]))
		}
	}
	generate(0, []int{})
	return comb
}

func hasDigit(cube []bool, d int) bool {
	if cube[d] {
		return true
	}
	if d == 6 && cube[9] {
		return true
	}
	if d == 9 && cube[6] {
		return true
	}
	return false
}

func canFormAll(required [][2]int, cube1, cube2 []bool) bool {
	for _, pair := range required {
		a, b := pair[0], pair[1]
		if !( (hasDigit(cube1, a) && hasDigit(cube2, b)) || (hasDigit(cube1, b) && hasDigit(cube2, a)) ) {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(cubeDigitPairs())
}