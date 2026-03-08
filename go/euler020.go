// https://projecteuler.net/problem=20

/*

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,

and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Answer: 648

*/

package main

import (

    "fmt"

    "math/big"

)

func factorial(n int) *big.Int {

    res := big.NewInt(1)

    for i := 2; i <= n; i++ {

        res.Mul(res, big.NewInt(int64(i)))

    }

    return res

}

func main() {

    fact := factorial(100)

    sum := 0

    for _, d := range fact.String() {

        sum += int(d - '0')

    }

    fmt.Println(sum)

}