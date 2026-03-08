// https://projecteuler.net/problem=3

/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer: 6857

*/

package main

import "fmt"

func main() {

    n := 600851475143

    largest := 0

    // Remove factors of 2

    for n%2 == 0 {

        n /= 2

        largest = 2

    }

    // Check odd factors

    for i := 3; i*i <= n; i += 2 {

        for n%i == 0 {

            n /= i

            largest = i

        }

    }

    // If n is prime greater than 2

    if n > 1 {

        largest = n

    }

    fmt.Println(largest)

}