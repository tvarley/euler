// https://projecteuler.net/problem=52
//
// Permuted Multiples
//
// It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
//
// Answer: 142857

package main

import (
	"fmt"
	"sort"
	"strconv"
)

func hasSameDigits(a, b int) bool {
	sa := strconv.Itoa(a)
	sb := strconv.Itoa(b)
	if len(sa) != len(sb) {
		return false
	}
	da := []byte(sa)
	db := []byte(sb)
	sort.Slice(da, func(i, j int) bool { return da[i] < da[j] })
	sort.Slice(db, func(i, j int) bool { return db[i] < db[j] })
	return string(da) == string(db)
}

func main() {
	for x := 1; ; x++ {
		allSame := true
		for mul := 2; mul <= 6; mul++ {
			if !hasSameDigits(x, x*mul) {
				allSame = false
				break
			}
		}
		if allSame {
			fmt.Println(x)
			break
		}
	}
}