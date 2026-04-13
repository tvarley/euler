// https://projecteuler.net/problem=88

// Product-sum Numbers

// A natural number, N, that can be written as the sum and product of a given set of at least two natural numbers, {a1, a2, ... , ak} is called a product-sum number: N = a1 + a2 + ... + ak = a1 × a2 × ... × ak.

// For example, 6 = 1 × 2 × 3 = 1 + 2 + 3.

// For a given set of size, k, we shall call the smallest such number a minimal product-sum number. The minimal product-sum numbers for sets of size, k = 2, 3, 4, 5, and 6 are as follows.

// k=2: 4 = 2 × 2 = 2 + 2
// k=3: 6 = 1 × 2 × 3 = 1 + 2 + 3
// k=4: 8 = 1 × 1 × 2 × 4 = 1 + 1 + 2 + 4
// k=5: 8 = 1 × 1 × 1 × 1 × 8 = 1 + 1 + 1 + 1 + 8
// k=6: 12 = 1 × 1 × 1 × 1 × 2 × 6 = 1 + 1 + 1 + 1 + 2 + 6

// Hence for 2≤k≤6, the sum of all the minimal product-sum numbers is 4+6+8+8+12 = 38; the sum for 2≤k≤12 is 61.

// What is the sum of all the minimal product-sum numbers for 2≤k≤12000?

// Answer: 7587457

// Execution time: ~50ms

// Optimizations: recursive factorization with dynamic k calculation and pruning (matches cpp/src/euler088.cpp:16)

// Interesting notes: fixed BFS issues (no 1s, queue explosion); uses non-decreasing factors >=2, implicit 1s via k=prod-sum+count

package main

import (
    "fmt"
)


func productSumNumbers() int64 {
    kmax := 12000
    minN := make([]int64, kmax+1)
    const max = int64(1 << 60)
    for i := range minN {
        minN[i] = max
    }
    limit := int64(1000000)
    var rec func(int64, int64, int, int)
    rec = func(prod, sumv int64, count, last int) {
        if prod > limit/2 {
            return
        }
        k := prod - sumv + int64(count)
        if k >= 2 && k <= int64(kmax) && prod < minN[k] {
            minN[k] = prod
        }
        for i := last; ; i++ {
            newProd := prod * int64(i)
            if newProd > limit || newProd/int64(i) != prod {
                break
            }
            rec(newProd, sumv+int64(i), count+1, i)
        }
    }
    rec(1, 0, 0, 2)
    set := make(map[int64]bool)
    for k := 2; k <= kmax; k++ {
        if minN[k] < max {
            set[minN[k]] = true
        }
    }
    sum := int64(0)
    for n := range set {
        sum += n
    }
    return sum
}

func main() {
    fmt.Println(productSumNumbers())
}