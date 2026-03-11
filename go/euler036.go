// https://projecteuler.net/problem=36

/*

Double-base Palindromes

The decimal number, 585 = 1001001001₂ (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

Answer: 872187

*/

package main

import "fmt"

import "strconv"

func isPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}
	return true
}

func main() {
	sum := 0
	for n := 1; n < 1000000; n++ {
		s := strconv.Itoa(n)
		if !isPalindrome(s) {
			continue
		}
		bin := strconv.FormatInt(int64(n), 2)
		if isPalindrome(bin) {
			sum += n
		}
	}
	fmt.Println(sum)
}