// https://projecteuler.net/problem=41

/*

Pandigital Prime

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

Answer: 7652413

*/

package main

import "fmt"

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func permutations(arr []int, start int, result *[]int) {
	if start == len(arr)-1 {
		num := 0
		for _, d := range arr {
			num = num*10 + d
		}
		*result = append(*result, num)
		return
	}
	for i := start; i < len(arr); i++ {
		arr[start], arr[i] = arr[i], arr[start]
		permutations(arr, start+1, result)
		arr[start], arr[i] = arr[i], arr[start]
	}
}

func main() {
	maxPrime := 0
	for n := 7; n >= 1; n-- {
		digits := make([]int, n)
		for i := 0; i < n; i++ {
			digits[i] = n - i
		}
		var nums []int
		permutations(digits, 0, &nums)
		for _, num := range nums {
			if isPrime(num) && num > maxPrime {
				maxPrime = num
			}
		}
		if maxPrime > 0 {
			break
		}
	}
	fmt.Println(maxPrime)
}