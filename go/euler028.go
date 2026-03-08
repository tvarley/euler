// https://projecteuler.net/problem=28

/*

Starting with the number 1 and moving to the right in a clockwise direction a
5 by 5 spiral is formed. The sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
formed in the same way?

Answer: 669171001

*/

package main

import "fmt"

func main() {
    sum := 1
    for n := 3; n <= 1001; n += 2 {
        corner := n * n
        sum += corner + (corner - (n - 1)) + (corner - 2*(n-1)) + (corner - 3*(n-1))
    }
    fmt.Println(sum)
}
