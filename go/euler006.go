// https://projecteuler.net/problem=6

/*

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Answer: 25164150

*/

package main

import "fmt"

func main() {

    n := 100

    sum := 0

    sumSq := 0

    for i := 1; i <= n; i++ {

        sum += i

        sumSq += i * i

    }

    sqSum := sum * sum

    diff := sqSum - sumSq

    fmt.Println(diff)

}