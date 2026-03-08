// https://projecteuler.net/problem=16

/*

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Answer: 1366

*/

package main

import (

    "fmt"

    "math/big"

)

func main() {

    two := big.NewInt(2)

    pow := new(big.Int).Exp(two, big.NewInt(1000), nil)

    sum := 0

    for _, d := range pow.String() {

        sum += int(d - '0')

    }

    fmt.Println(sum)

}