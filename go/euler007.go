// https://projecteuler.net/problem=7

/*

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer: 104743

*/

package main

import "fmt"

func sieve(limit int) []bool {

    isPrime := make([]bool, limit+1)

    for i := range isPrime {

        isPrime[i] = true

    }

    isPrime[0], isPrime[1] = false, false

    for i := 2; i*i <= limit; i++ {

        if isPrime[i] {

            for j := i * i; j <= limit; j += i {

                isPrime[j] = false

            }

        }

    }

    return isPrime

}

func main() {

    limit := 200000

    primes := sieve(limit)

    count := 0

    for i := 2; i <= limit; i++ {

        if primes[i] {

            count++

            if count == 10001 {

                fmt.Println(i)

                return

            }

        }

    }

}