// https://projecteuler.net/problem=14

/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)

n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Answer: 837799

*/

package main

import "fmt"

func collatzLength(n int, memo map[int]int) int {

    if n == 1 {

        return 1

    }

    if length, ok := memo[n]; ok {

        return length

    }

    var next int

    if n%2 == 0 {

        next = n / 2

    } else {

        next = 3*n + 1

    }

    length := 1 + collatzLength(next, memo)

    memo[n] = length

    return length

}

func main() {

    memo := make(map[int]int)

    maxLength := 0

    maxStart := 0

    for i := 1; i < 1000000; i++ {

        length := collatzLength(i, memo)

        if length > maxLength {

            maxLength = length

            maxStart = i

        }

    }

    fmt.Println(maxStart)

}