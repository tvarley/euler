// https://projecteuler.net/problem=9

/*

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.

Find the product abc.

Answer: 31875000

*/

package main

import "fmt"

func main() {

    for a := 1; a < 333; a++ {

        for b := a + 1; b < (1000-a)/2; b++ {

            c := 1000 - a - b

            if a*a + b*b == c*c {

                fmt.Println(a * b * c)

                return

            }

        }

    }

}