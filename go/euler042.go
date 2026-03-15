// https://projecteuler.net/problem=42

/*

Coded Triangle Numbers

The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, …

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

Answer: 162

*/

package main

import "fmt"

import "strings"

import "os"

import "math"

func isTriangle(n int) bool {
	disc := 1 + 8*n
	k := int(math.Sqrt(float64(disc)))
	return k*k == disc && (k-1)%2 == 0
}

func wordValue(word string) int {
	val := 0
	for _, c := range word {
		val += int(c - 'A' + 1)
	}
	return val
}

func main() {
	data, _ := os.ReadFile("p042_words.txt")
	content := string(data)
	content = strings.ReplaceAll(content, "\"", "")
	words := strings.Split(content, ",")
	count := 0
	for _, word := range words {
		if isTriangle(wordValue(word)) {
			count++
		}
	}
	fmt.Println(count)
}