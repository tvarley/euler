// https://projecteuler.net/problem=30

/*

Surprisingly there are only three numbers that can be written as the sum of
fourth powers of their digits: 1634, 8208, 9474.

Find the sum of all the numbers that can be written as the sum of fifth powers
of their digits.

Answer: 443839

*/

package main

import "fmt"

func digitFifthPowerSum(n int) int {
    sum := 0
    for n > 0 {
        d := n % 10
        p := d * d * d * d * d
        sum += p
        n /= 10
    }
    return sum
}

func main() {
    total := 0
    for i := 2; i <= 354294; i++ {
        if digitFifthPowerSum(i) == i {
            total += i
        }
    }
    fmt.Println(total)
}
