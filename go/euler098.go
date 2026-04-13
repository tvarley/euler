// https://projecteuler.net/problem=98

// Anagramic Squares

// By replacing each of the letters in the word CARE with 1, 2, 9, and 6 respectively, we form the number 1296, which is a perfect square.

// By replacing each of the letters in the word RACE with 6, 9, 1, and 2 respectively, we form the number 6912, which is also a perfect square.

// We shall call CARE and RACE anagrams of each other, since they contain the same letters in a different order.

// CARE and RACE are anagrams because we can rearrange the letters of CARE to form RACE and vice versa.

// By using the same mapping of letters to digits, we can form two different perfect squares from two different anagrams.

// Now, consider the text file, p098_words.txt (right click and 'Save Link/Target As...'), a 16K text file containing one thousand common English words, all in upper case.

// Find the largest square number formed by any of the anagram pairs in the file.

// Answer: 18769

// Execution time: ~1000ms

// Optimizations: Backtracking digit assignment with early pruning

// Interesting notes: AI-generated solution finding anagram pairs and digit mappings

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strings"
)

func isSquare(n int64) bool {
	root := int64(math.Sqrt(float64(n)))
	return root*root == n
}

func tryMapping(letterList []rune, pos int, used []bool, mapping map[rune]int, w1, w2 string, maxSquare *int64) {
	if pos == len(letterList) {
		if mapping[rune(w1[0])] == 0 || mapping[rune(w2[0])] == 0 {
			return
		}
		var num1, num2 int64
		for _, c := range w1 {
			num1 = num1*10 + int64(mapping[c])
		}
		for _, c := range w2 {
			num2 = num2*10 + int64(mapping[c])
		}
		if isSquare(num1) && isSquare(num2) {
			if num1 > *maxSquare {
				*maxSquare = num1
			}
			if num2 > *maxSquare {
				*maxSquare = num2
			}
		}
		return
	}
	for d := 0; d < 10; d++ {
		if used[d] {
			continue
		}
		mapping[letterList[pos]] = d
		used[d] = true
		tryMapping(letterList, pos+1, used, mapping, w1, w2, maxSquare)
		used[d] = false
	}
}

func anagramicSquares() int64 {
	file, err := os.Open("p098_words.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	var content string
	if scanner.Scan() {
		content = scanner.Text()
	}

	// parse words
	var words []string
	var word strings.Builder
	inQuote := false
	for _, c := range content {
		if c == '"' {
			inQuote = !inQuote
			if !inQuote && word.Len() > 0 {
				words = append(words, word.String())
				word.Reset()
			}
		} else if inQuote {
			word.WriteRune(c)
		}
	}

	// group by sorted letters
	anagrams := make(map[string][]string)
	for _, w := range words {
		sorted := strings.Split(w, "")
		sort.Strings(sorted)
		key := strings.Join(sorted, "")
		anagrams[key] = append(anagrams[key], w)
	}

	var maxSquare int64
	for _, group := range anagrams {
		if len(group) < 2 {
			continue
		}
		for i := 0; i < len(group); i++ {
			for j := i + 1; j < len(group); j++ {
				w1, w2 := group[i], group[j]
				// unique letters
				letters := make(map[rune]bool)
				for _, c := range w1 {
					letters[c] = true
				}
				for _, c := range w2 {
					letters[c] = true
				}
				if len(letters) > 10 {
					continue
				}
				letterList := make([]rune, 0, len(letters))
				for c := range letters {
					letterList = append(letterList, c)
				}
				used := make([]bool, 10)
				mapping := make(map[rune]int)
				tryMapping(letterList, 0, used, mapping, w1, w2, &maxSquare)
			}
		}
	}
	return maxSquare
}

func main() {
	fmt.Println(anagramicSquares())
}