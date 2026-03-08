// https://projecteuler.net/problem=23

/*

A perfect number is a number for which the sum of its proper divisors is
exactly equal to the number. A number n is called deficient if the sum of its
proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, the smallest number that can be written
as the sum of two abundant numbers is 24. By mathematical analysis, it can be
shown that all integers greater than 28123 can be written as the sum of two
abundant numbers. Find the sum of all the positive integers which cannot be
written as the sum of two abundant numbers.

Answer: 4179871

*/

package main

import "fmt"

func sumDiv(n int) int {
    sum := 1
    for i := 2; i*i <= n; i++ {
        if n%i == 0 {
            sum += i
            if i != n/i {
                sum += n / i
            }
        }
    }
    return sum
}

func main() {
    const limit = 28124
    var abundants []int
    for i := 2; i < limit; i++ {
        if sumDiv(i) > i {
            abundants = append(abundants, i)
        }
    }

    canWrite := make([]bool, limit)
    for i, a := range abundants {
        for _, b := range abundants[i:] {
            s := a + b
            if s >= limit {
                break
            }
            canWrite[s] = true
        }
    }

    total := 0
    for i := 1; i < limit; i++ {
        if !canWrite[i] {
            total += i
        }
    }

    fmt.Println(total)
}
