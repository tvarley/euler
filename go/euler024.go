// https://projecteuler.net/problem=24

/*

A permutation is an ordered arrangement of objects. The lexicographic
permutations of 0, 1 and 2 are: 012 021 102 120 201 210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
5, 6, 7, 8 and 9?

Answer: 2783915460

*/

package main

import "fmt"

func factorial(n int) int {
    if n <= 1 {
        return 1
    }
    return n * factorial(n-1)
}

func main() {
    digits := []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    n := 1000000 - 1

    result := ""
    for len(digits) > 0 {
        f := factorial(len(digits) - 1)
        idx := n / f
        result += fmt.Sprintf("%d", digits[idx])
        digits = append(digits[:idx], digits[idx+1:]...)
        n %= f
    }

    fmt.Println(result)
}
