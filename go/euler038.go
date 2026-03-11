// https://projecteuler.net/problem=38

/*

Pandigital Multiples

Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192

192 × 2 = 384

192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3).

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2,…,n) where n > 1?

Answer: 932718654

*/

package main

import "fmt"

import "strconv"

func isPandigital(s string) bool {
	if len(s) != 9 {
		return false
	}
	digits := make([]int, 10)
	for _, c := range s {
		if c == '0' {
			return false
		}
		d := int(c - '0')
		if digits[d] > 0 {
			return false
		}
		digits[d]++
	}
	return true
}

func main() {
	max := 0
	for n := 1; n < 10000; n++ {
		s := ""
		for i := 1; ; i++ {
			s += strconv.Itoa(n * i)
			if len(s) > 9 {
				break
			}
			if len(s) == 9 && isPandigital(s) {
				p, _ := strconv.Atoi(s)
				if p > max {
					max = p
				}
				break
			}
		}
	}
	fmt.Println(max)
}