// https://projecteuler.net/problem=89

// Roman Numerals

// For a number written in Roman numerals to be considered valid there are basic rules which must be followed. Even though the rules allow some numbers to be expressed in more than one way there is always a "best" way of writing a particular number.

// For example, it would appear that there are at least six ways of writing the number sixteen:

// IIIIIIIIIIIIIIII
// VIIIIIIIIIIIIDC
// VVIIIIIIIIDC
// XIIIIIIIIIIIIDC
// VVVIIDC
// XVIDC

// However, according to the rules only XIIIIIIIIIIDC is valid.

// In this problem we consider all ways of writing a number in valid Roman numerals, and we are interested in the number of characters saved by writing the number in its minimal form.

// For example, 1969 is written as MCMLXIX but could be written as MCMXCIX. The latter uses 9 characters whereas the former uses 7 characters. So 1969 saves 2 characters.

// The text file, p089_roman.txt (right click and 'Save Link/Target As...'), contains one thousand numbers written in valid, but not necessarily minimal Roman numerals; see About... Roman Numerals for the definitive rules for this problem.

// Find the number of characters saved by writing each of these in their minimal form.

// Note: You can assume that all the Roman numerals in the file contain no more than four consecutive identical units.

// Answer: 743

// Execution time: ~0ms

// Optimizations: Precomputed Roman numeral conversion

// Interesting notes: AI-generated solution processing Roman numerals from file

package main

import (
	"bufio"
	"fmt"
	"os"
)

func romanToInt(s string) int {
	values := []struct {
		sym string
		val int
	}{
		{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
		{"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
		{"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1},
	}
	total := 0
	i := 0
	for i < len(s) {
		found := false
		for _, p := range values {
			if i+len(p.sym) <= len(s) && s[i:i+len(p.sym)] == p.sym {
				total += p.val
				i += len(p.sym)
				found = true
				break
			}
		}
		if !found {
			i++
		}
	}
	return total
}

func intToRoman(num int) string {
	val := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	sym := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	result := ""
	for i := 0; i < len(val); i++ {
		for num >= val[i] {
			result += sym[i]
			num -= val[i]
		}
	}
	return result
}

func romanNumerals() int {
	file, err := os.Open("p089_roman.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	totalSaved := 0
	for scanner.Scan() {
		roman := scanner.Text()
		if roman == "" {
			continue
		}
		value := romanToInt(roman)
		minimal := intToRoman(value)
		saved := len(roman) - len(minimal)
		totalSaved += saved
	}
	return totalSaved
}

func main() {
	fmt.Println(romanNumerals())
}