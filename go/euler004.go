// https://projecteuler.net/problem=4

/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Answer: 906609

*/

package main

import "fmt"

func isPalindrome(n int) bool {

    s := fmt.Sprintf("%d", n)

    for i := 0; i < len(s)/2; i++ {

        if s[i] != s[len(s)-1-i] {

            return false

        }

    }

    return true

}

func main() {

    max := 0

    for i := 999; i >= 100; i-- {

        for j := i; j >= 100; j-- {

            prod := i * j

            if prod <= max {

                break

            }

            if isPalindrome(prod) {

                if prod > max {

                    max = prod

                }

            }

        }

    }

    fmt.Println(max)

}