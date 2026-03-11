// https://projecteuler.net/problem=34

/*

Digit Factorials

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.

Answer: 40730

*/

package main

import "fmt"

import "strconv"

func fact(n int) int {
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}

func main() {
	facts := make([]int, 10)
	for i := 0; i < 10; i++ {
		facts[i] = fact(i)
	}
	sum := 0
	for n := 3; n < 100000; n++ {
		s := strconv.Itoa(n)
		total := 0
		for _, c := range s {
			total += facts[int(c-'0')]
		}
		if total == n {
			sum += n
		}
	}
	fmt.Println(sum)
}