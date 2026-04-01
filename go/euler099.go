// https://projecteuler.net/problem=99

// Largest Exponential

// Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.

// However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.

// Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

// Answer: 709

// Execution time: ~0ms

// Optimizations: Logarithmic comparison to avoid large number computation

// Interesting notes: AI-generated solution using log properties for comparison

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func largestExponential() int {
	file, err := os.Open("p099_base_exp.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	lineNum := 0
	maxLine := 0
	maxVal := 0.0
	for scanner.Scan() {
		lineNum++
		parts := strings.Split(scanner.Text(), ",")
		base, _ := strconv.Atoi(parts[0])
		exp, _ := strconv.Atoi(parts[1])
		val := float64(exp) * math.Log(float64(base))
		if val > maxVal {
			maxVal = val
			maxLine = lineNum
		}
	}
	return maxLine
}

func main() {
	fmt.Println(largestExponential())
}