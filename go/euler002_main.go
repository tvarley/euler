//go:build !test
package main

import (
	"fmt"
	"github.com/tvarley/euler/go/euler"
)

func main() {
	fmt.Println(euler.SumEvenFib(4000000))
}