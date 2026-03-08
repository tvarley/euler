// https://projecteuler.net/problem=25

/*

The Fibonacci sequence is defined by the recurrence relation:
Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

Answer: 4782

*/

package main

import (
    "fmt"
    "math/big"
)

func main() {
    target := new(big.Int)
    target.Exp(big.NewInt(10), big.NewInt(999), nil)

    a := big.NewInt(1)
    b := big.NewInt(1)
    idx := 2

    for a.Cmp(target) < 0 {
        next := new(big.Int).Add(a, b)
        a, b = next, a
        idx++
    }

    fmt.Println(idx)
}
