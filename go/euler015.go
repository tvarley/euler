// https://projecteuler.net/problem=15

/*

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

Answer: 137846528820

*/

package main

import (

    "fmt"

    "math/big"

)

func binomial(n, k int64) *big.Int {

    if k > n-k {

        k = n - k

    }

    res := big.NewInt(1)

    for i := int64(1); i <= k; i++ {

        res.Mul(res, big.NewInt(n-i+1))

        res.Div(res, big.NewInt(i))

    }

    return res

}

func main() {

    fmt.Println(binomial(40, 20))

}