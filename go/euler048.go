// https://projecteuler.net/problem=48

/*

Self Powers

The series, 1¹ + 2² + 3³ + … + 10¹⁰ = 10405071317.

Find the last ten digits of the series, 1¹ + 2² + 3³ + … + 1000¹⁰⁰⁰.

Answer: 9110846700

*/

package main

import "fmt"

import "math/big"

func main() {
	mod := big.NewInt(10000000000)
	sum := big.NewInt(0)
	for i := 1; i <= 1000; i++ {
		pow := big.NewInt(int64(i))
		pow.Exp(pow, big.NewInt(int64(i)), nil)
		sum.Add(sum, pow)
		sum.Mod(sum, mod)
	}
	fmt.Println(sum)
}