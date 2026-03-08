// https://projecteuler.net/problem=29

/*

Consider all integer combinations of a^b for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5.
How many distinct terms are there for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?

Answer: 9183

*/

package main

import (
    "fmt"
    "math/big"
)

func main() {
    seen := make(map[string]bool)
    for a := 2; a <= 100; a++ {
        for b := 2; b <= 100; b++ {
            val := new(big.Int).Exp(big.NewInt(int64(a)), big.NewInt(int64(b)), nil)
            seen[val.String()] = true
        }
    }
    fmt.Println(len(seen))
}
