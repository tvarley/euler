// https://projecteuler.net/problem=65

// Convergents of e

// The square root of 2 can be written as an infinite continued fraction.
// √2 = 1 + 1/(2 + 1/(2 + 1/(2 + ...)))
// The infinite continued fraction can be written, √2 = [1;(2)], (2) indicates that 2 repeats ad infinitum.
// In a similar way, √23 = [4; (1,3,1,8)].
// It turns out that the sequence of partial values of continued fractions for square roots provide the best rational approximations.
// Let us consider the convergents for √2.
// 1 + 1/2 = 3/2
// 1 + 1/(2 + 1/2) = 7/5
// 1 + 1/(2 + 1/(2 + 1/2)) = 17/12
// 1 + 1/(2 + 1/(2 + 1/2)) = 41/29
// Hence the sequence of the first ten convergents for √2 are:
// 1, 3/2, 7/5, 17/12, 41/29, 99/70, 239/169, 577/408, 1393/985, 3363/2378, ...
// What is most surprising is that the important mathematical constant,
// e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1, ..., 1, 2k, 1, ...]
// The first ten terms in the sequence of convergents for e are:
// 2, 3, 8/3, 11/4, 19/7, 87/32, 106/39, 193/71, 1264/465, 1457/536, ...
// The sum of digits in the numerator of the 10th convergent is 1+4+5+7=17.
// Find the sum of digits in the numerator of the 100th convergent of the continued fraction for e.

// Answer: 272

// Execution time: ~0ms on modern hardware

// Optimizations: Simple big integer arithmetic using strings for numerator calculation
// Interesting notes: AI-generated solution implementing continued fraction convergents with string-based big integers

package main

import (
	"fmt"
	"strconv"
)

func addBig(a, b string) string {
	result := ""
	carry := 0
	i := len(a) - 1
	j := len(b) - 1
	for i >= 0 || j >= 0 || carry > 0 {
		sum := carry
		if i >= 0 {
			sum += int(a[i] - '0')
			i--
		}
		if j >= 0 {
			sum += int(b[j] - '0')
			j--
		}
		carry = sum / 10
		result = strconv.Itoa(sum%10) + result
	}
	return result
}

func multiplyBig(a string, b int) string {
	result := ""
	carry := 0
	for i := len(a) - 1; i >= 0; i-- {
		prod := int(a[i]-'0')*b + carry
		carry = prod / 10
		result = strconv.Itoa(prod%10) + result
	}
	for carry > 0 {
		result = strconv.Itoa(carry%10) + result
		carry /= 10
	}
	return result
}

func sumDigitsBig(s string) int {
	sum := 0
	for _, c := range s {
		sum += int(c - '0')
	}
	return sum
}

func convergentsOfE() int {
	terms := []int{2}
	for k := 1; ; k++ {
		terms = append(terms, 1)
		terms = append(terms, 2*k)
		terms = append(terms, 1)
		if len(terms) >= 101 {
			break
		}
	}
	hPrev2 := "0"
	hPrev1 := "1"
	kPrev2 := "1"
	kPrev1 := "0"
	for i := 0; i < 100; i++ {
		h := addBig(multiplyBig(hPrev1, terms[i]), hPrev2)
		k := addBig(multiplyBig(kPrev1, terms[i]), kPrev2)
		hPrev2 = hPrev1
		hPrev1 = h
		kPrev2 = kPrev1
		kPrev1 = k
	}
	return sumDigitsBig(hPrev1)
}

func main() {
	fmt.Println(convergentsOfE())
}