// https://projecteuler.net/problem=26

/*

A unit fraction contains 1 in the numerator. It can be seen that 1/7 has a
6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle
in its decimal fraction part.

Answer: 983

*/

package main

import "fmt"

func cycleLength(d int) int {
    remainders := make(map[int]int)
    r := 1
    pos := 0
    for r != 0 {
        if prev, ok := remainders[r]; ok {
            return pos - prev
        }
        remainders[r] = pos
        r = (r * 10) % d
        pos++
    }
    return 0
}

func main() {
    best, bestLen := 0, 0
    for d := 2; d < 1000; d++ {
        l := cycleLength(d)
        if l > bestLen {
            bestLen = l
            best = d
        }
    }
    fmt.Println(best)
}
