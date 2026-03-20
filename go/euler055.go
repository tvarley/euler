// https://projecteuler.net/problem=55
//
// Lychrel Numbers
//
// If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.
// Not all numbers produce palindromes so quickly. For example, 349 took three iterations.
// Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome.
// A number that never forms a palindrome through the reverse and add process is called a Lychrel number.
// Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise.
// In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome.
// In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).
// Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.
// How many Lychrel numbers are there below ten-thousand?
// NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
//
// Answer: 249

package main

import (
	"fmt"
	"math/big"
	"strconv"
)

func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func isPalindrome(s string) bool {
	return s == reverse(s)
}

func isLychrel(n int) bool {
	num := big.NewInt(int64(n))
	for i := 0; i < 50; i++ {
		rev := new(big.Int).SetBytes([]byte(reverse(num.String())))
		num.Add(num, rev)
		if isPalindrome(num.String()) {
			return false
		}
	}
	return true
}

func main() {
	count := 0
	for i := 1; i < 10000; i++ {
		if isLychrel(i) {
			count++
		}
	}
	fmt.Println(count)
}