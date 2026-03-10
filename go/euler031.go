// https://projecteuler.net/problem=31

/*

In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

Answer: 73682

*/

package main

import "fmt"

func coinSums(target int) int {
	coins := []int{1, 2, 5, 10, 20, 50, 100, 200}
	ways := make([]int, target+1)
	ways[0] = 1
	for _, coin := range coins {
		for j := coin; j <= target; j++ {
			ways[j] += ways[j-coin]
		}
	}
	return ways[target]
}

func main() {
	fmt.Println(coinSums(200))
}