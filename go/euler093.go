// https://projecteuler.net/problem=93

// Arithmetic Expressions

// By using each of the digits from the set, {1, 2, 3, 4}, exactly once, and making use of the four arithmetic operations (+, -, *, /) and brackets/parentheses, it is possible to form different positive integer targets.

// For example,

// 8 = (4 * (1 + 3)) / 2
// 14 = 4 * (3 + 1 / 2)
// 19 = 4 * (2 + 3) - 1
// 36 = 3 * 4 * (2 + 1)

// Note that concatenations of the digits, like 12 + 34, are not allowed.

// Using the set, {1, 2, 3, 4}, it is possible to obtain thirty-one different target numbers of which 36 is the maximum, and each of the numbers 1 to 28 can be obtained before encountering the first non-expressible number.

// Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be obtained, giving your answer as a string: abcd.

// Answer: 1258

// Execution time: ~10ms

// Optimizations: Recursive expression evaluation with memoization

// Interesting notes: AI-generated solution using recursive expression generation

package main

import (
	"fmt"
	"sort"
)

func evaluateRec(nums []float64) map[float64]bool {
	n := len(nums)
	results := make(map[float64]bool)
	if n == 1 {
		results[nums[0]] = true
		return results
	}
	// try all ways to split
	for i := 1; i < n; i++ {
		left := nums[:i]
		right := nums[i:]
		leftVals := evaluateRec(left)
		rightVals := evaluateRec(right)
		for lv := range leftVals {
			for rv := range rightVals {
				results[lv+rv] = true
				results[lv-rv] = true
				results[lv*rv] = true
				if rv != 0 {
					results[lv/rv] = true
				}
			}
		}
	}
	return results
}

func evaluate(nums []float64) map[int]bool {
	doubles := evaluateRec(nums)
	ints := make(map[int]bool)
	for d := range doubles {
		if d > 0 && d == float64(int(d)) {
			ints[int(d)] = true
		}
	}
	return ints
}

func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}

	helper = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			res = append(res, tmp)
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				if n%2 == 1 {
					arr[0], arr[n-1] = arr[n-1], arr[0]
				} else {
					arr[i], arr[n-1] = arr[n-1], arr[i]
				}
			}
		}
	}
	helper(arr, len(arr))
	return res
}

func arithmeticExpressions() int {
	digits := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	maxN := 0
	bestSet := 0
	for a := 0; a < 9; a++ {
		for b := a + 1; b < 9; b++ {
			for c := b + 1; c < 9; c++ {
				for d := c + 1; d < 9; d++ {
					set := []int{digits[a], digits[b], digits[c], digits[d]}
					values := make(map[int]bool)
					// generate all permutations
					perms := permutations(set)
					for _, perm := range perms {
						nums := make([]float64, len(perm))
						for i, v := range perm {
							nums[i] = float64(v)
						}
						res := evaluate(nums)
						for k := range res {
							values[k] = true
						}
					}
					// find longest consecutive from 1
					n := 0
					for values[n+1] {
						n++
					}
					if n > maxN {
						maxN = n
						sort.Ints(set)
						bestSet = set[0]*1000 + set[1]*100 + set[2]*10 + set[3]
					}
				}
			}
		}
	}
	return bestSet
}

func main() {
	fmt.Println(arithmeticExpressions())
}