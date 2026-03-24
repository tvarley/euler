// https://projecteuler.net/problem=68

// Magic 5-gon ring

// Consider the following "magic" 3-gon ring, filled with the numbers 1 to 6, and each line adding to nine.
// Working clockwise, and starting from the group of three with the numerically lowest external node (4,3,2 in this example), each solution can be described uniquely. For example, the above solution can be described by the set: 4,3,2; 6,2,1; 5,1,3.
// It is possible to complete the ring with four different totals: 9, 10, 11, and 12. There are eight solutions in total.
// Total	Solution Set
// 9	4,2,3; 5,3,1; 6,1,2
// 9	4,3,2; 6,2,1; 5,1,3
// 10	2,3,5; 4,5,1; 6,1,3
// 10	2,5,3; 6,3,1; 4,1,5
// 10	3,2,5; 4,5,1; 6,1,3
// 10	3,5,2; 6,2,1; 4,1,5
// 11	6,4,1; 5,1,4; 2,4,3
// 11	6,1,4; 2,4,1; 5,1,4
// 12	3,2,6; 5,6,1; 4,1,5
// 12	3,6,2; 5,2,1; 4,1,5
// 12	6,2,3; 5,3,1; 4,1,5
// 12	6,3,2; 5,2,1; 4,1,5
// By concatenating each group it is possible to form 9-digit strings; the maximum string for a 3-gon ring is 432621513.
// Using the numbers 1 to 10, and depending on arrangements, it is possible to form 16- and 17-digit strings. What is the maximum 16-digit string for a "magic" 5-gon ring?

// Answer: 6531031914842725

// Execution time: ~0ms on modern hardware

// Optimizations: Generate permutations of digits, check magic property
// Interesting notes: AI-generated solution using permutation generation for magic 5-gon rings

package main

import (
	"fmt"
	"strconv"
)

func magic5GonRing() string {
	digits := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	maxString := ""
	permute(digits, func(perm []int) {
		outer := perm[5:10]
		inner := perm[0:5]
		sumVal := outer[0] + inner[0] + inner[1]
		if outer[1]+inner[1]+inner[2] != sumVal || outer[2]+inner[2]+inner[3] != sumVal ||
			outer[3]+inner[3]+inner[4] != sumVal || outer[4]+inner[4]+inner[0] != sumVal {
			return
		}
		minOuter := outer[0]
		minIdx := 0
		for i, v := range outer {
			if v < minOuter {
				minOuter = v
				minIdx = i
			}
		}
		s := ""
		for i := 0; i < 5; i++ {
			idx := (minIdx + i) % 5
			s += strconv.Itoa(outer[idx]) + strconv.Itoa(inner[idx]) + strconv.Itoa(inner[(idx+1)%5])
		}
		if len(s) == 16 && s > maxString {
			maxString = s
		}
	})
	return maxString
}

func permute(arr []int, f func([]int)) {
	n := len(arr)
	c := make([]int, n)
	f(arr)
	i := 0
	for i < n {
		if c[i] < i {
			if i%2 == 0 {
				arr[0], arr[i] = arr[i], arr[0]
			} else {
				arr[c[i]], arr[i] = arr[i], arr[c[i]]
			}
			f(arr)
			c[i]++
			i = 0
		} else {
			c[i] = 0
			i++
		}
	}
}

func main() {
	fmt.Println(magic5GonRing())
}