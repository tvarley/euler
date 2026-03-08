// https://projecteuler.net/problem=10

/*

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Answer: 142913828922

*/

package main

import "fmt"

func sieve(limit int) []bool {

    isPrime := make([]bool, limit)

    for i := range isPrime {

        isPrime[i] = true

    }

    isPrime[0], isPrime[1] = false, false

    for i := 2; i*i < limit; i++ {

        if isPrime[i] {

            for j := i * i; j < limit; j += i {

                isPrime[j] = false

            }

        }

    }

    return isPrime

}

func main() {

    limit := 2000000

    primes := sieve(limit)

    sum := int64(0)

    for i := 2; i < limit; i++ {

        if primes[i] {

            sum += int64(i)

        }

    }

    fmt.Println(sum)

}