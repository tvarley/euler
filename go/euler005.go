// https://projecteuler.net/problem=5

/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Answer: 232792560

*/

package main

import "fmt"

func gcd(a, b int64) int64 {

    for b != 0 {

        a, b = b, a%b

    }

    return a

}

func lcm(a, b int64) int64 {

    return a / gcd(a, b) * b

}

func main() {

    n := int64(1)

    for i := int64(2); i <= 20; i++ {

        n = lcm(n, i)

    }

    fmt.Println(n)

}