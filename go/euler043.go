// https://projecteuler.net/problem=43

/*

Sub-string Divisibility

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2 d3 d4=406 is divisible by 2
d3 d4 d5=063 is divisible by 3
d4 d5 d6=635 is divisible by 5
d5 d6 d7=357 is divisible by 7
d6 d7 d8=572 is divisible by 11
d7 d8 d9=728 is divisible by 13
d8 d9 d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

Answer: 16695334890

*/

package main

import "fmt"

import "strconv"

func permutations(arr []int, start int, result *[]string) {
	if start == len(arr)-1 {
		s := ""
		for _, d := range arr {
			s += strconv.Itoa(d)
		}
		*result = append(*result, s)
		return
	}
	for i := start; i < len(arr); i++ {
		arr[start], arr[i] = arr[i], arr[start]
		permutations(arr, start+1, result)
		arr[start], arr[i] = arr[i], arr[start]
	}
}

func checkDiv(s string) bool {
	divisors := []int{2, 3, 5, 7, 11, 13, 17}
	for i, div := range divisors {
		sub := s[i+1 : i+4]
		num, _ := strconv.Atoi(sub)
		if num%div != 0 {
			return false
		}
	}
	return true
}

func main() {
	digits := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	var perms []string
	permutations(digits, 0, &perms)
	sum := 0
	for _, p := range perms {
		if p[0] != '0' && checkDiv(p) {
			num, _ := strconv.Atoi(p)
			sum += num
		}
	}
	fmt.Println(sum)
}