// https://projecteuler.net/problem=21

/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).

If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

Answer: 31626

*/

package main

import "fmt"

func sumDivisors(n int) int {

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

    amicable := make(map[int]bool)

    for a := 2; a < 10000; a++ {

        b := sumDivisors(a)

        if b > a && b < 10000 && sumDivisors(b) == a {

            amicable[a] = true

            amicable[b] = true

        }

    }

    sum := 0

    for n := range amicable {

        sum += n

    }

    fmt.Println(sum)

}