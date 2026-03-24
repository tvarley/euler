// https://projecteuler.net/problem=62

// Cubic Permutations

// The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
// Find the smallest cube for which exactly five permutations of its digits are cube.

// Answer: 127035954683

// Execution time: ~1ms on modern hardware

// Optimizations: Group cubes by sorted digit string for efficient permutation lookup
// Interesting notes: AI-generated solution using digit sorting and grouping

package main

import (
	"fmt"
	"sort"
	"strconv"
)

func cubicPermutations() int64 {
	groups := make(map[string][]int64)
	for n := int64(1); ; n++ {
		cube := n * n * n
		s := strconv.FormatInt(cube, 10)
		if len(s) > 12 {
			break
		}
		key := s
		runes := []rune(key)
		sort.Slice(runes, func(i, j int) bool { return runes[i] < runes[j] })
		key = string(runes)
		groups[key] = append(groups[key], cube)
	}
	minCube := int64(1<<63 - 1) // max int64
	for _, group := range groups {
		if len(group) == 5 {
			for _, c := range group {
				if c < minCube {
					minCube = c
				}
			}
		}
	}
	return minCube
}

func main() {
	fmt.Println(cubicPermutations())
}