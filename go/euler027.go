// https://projecteuler.net/problem=27

/*

Euler discovered the remarkable quadratic formula: n² + n + 41
The incredible formula n² − 79n + 1601 produces 80 primes for n = 0 to 79.

Considering quadratics of the form n² + an + b, where |a| < 1000 and |b| < 1000,
find the product of the coefficients a and b for the quadratic expression that
produces the maximum number of primes for consecutive values of n, starting
with n = 0.

Answer: -59231

*/

package main

import "fmt"

func isPrime27(n int) bool {
    if n < 2 {
        return false
    }
    if n == 2 {
        return true
    }
    if n%2 == 0 {
        return false
    }
    for i := 3; i*i <= n; i += 2 {
        if n%i == 0 {
            return false
        }
    }
    return true
}

func main() {
    bestProduct, bestStreak := 0, 0
    for a := -999; a < 1000; a++ {
        for b := -999; b < 1000; b++ {
            n := 0
            for isPrime27(n*n + a*n + b) {
                n++
            }
            if n > bestStreak {
                bestStreak = n
                bestProduct = a * b
            }
        }
    }
    fmt.Println(bestProduct)
}
