package main

import (
	"fmt"
	"math"
	"math/big"
)

func isSquare(n int) bool {
	s := int(math.Sqrt(float64(n)))
	return s*s == n
}

func pellMinimalX(d int) *big.Int {
	a0 := int(math.Sqrt(float64(d)))
	if a0*a0 == d {
		return big.NewInt(0)
	}
	h := big.NewInt(int64(a0))
	k := big.NewInt(1)
	diff := new(big.Int).Sub(new(big.Int).Mul(h, h), new(big.Int).Mul(big.NewInt(int64(d)), new(big.Int).Mul(k, k)))
	if diff.Cmp(big.NewInt(1)) == 0 {
		return h
	}
	m := 0
	dv := 1
	a := a0
	hm2 := big.NewInt(1)
	hm1 := big.NewInt(int64(a0))
	km2 := big.NewInt(0)
	km1 := big.NewInt(1)
	for {
		m = dv * a - m
		dv = (d - m*m) / dv
		a = (a0 + m) / dv
		tt := big.NewInt(int64(a))
		h = new(big.Int).Add(new(big.Int).Mul(tt, hm1), hm2)
		k = new(big.Int).Add(new(big.Int).Mul(tt, km1), km2)
		diff = new(big.Int).Sub(new(big.Int).Mul(h, h), new(big.Int).Mul(big.NewInt(int64(d)), new(big.Int).Mul(k, k)))
		if diff.Cmp(big.NewInt(1)) == 0 {
			return h
		}
		hm2 = hm1
		hm1 = h
		km2 = km1
		km1 = k
	}
}

func diophantineEquation() int {
	maxX := big.NewInt(0)
	maxD := 0
	for d := 2; d <= 1000; d++ {
		if isSquare(d) {
			continue
		}
		x := pellMinimalX(d)
		if x.Cmp(maxX) > 0 {
			maxX = x
			maxD = d
		}
	}
	return maxD
}

func main() {
	fmt.Println(diophantineEquation())
}