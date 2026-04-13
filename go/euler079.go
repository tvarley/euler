// https://projecteuler.net/problem=79

// Passcode Derivation

// A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

// The text file, keylog.txt, contains fifty successful login attempts.

// Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.

// Answer: 73162890

// Execution time: ~0ms

// Optimizations: Topological sort on digit constraints

// Interesting notes: AI-generated solution using graph-based approach

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func passcodeDerivation() string {
	file, err := os.Open("keylog.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	triples := [][]int{}
	for scanner.Scan() {
		line := scanner.Text()
		if len(line) == 3 {
			t := make([]int, 3)
			for i, c := range line {
				t[i] = int(c - '0')
			}
			triples = append(triples, t)
		}
	}
	digits := make(map[int]bool)
	for _, t := range triples {
		for _, d := range t {
			digits[d] = true
		}
	}
	graph := make(map[int][]int)
	inDegree := make(map[int]int)
	for d := range digits {
		inDegree[d] = 0
	}
	for _, t := range triples {
		a, b, c := t[0], t[1], t[2]
		if a != b {
			if !contains(graph[a], b) {
				graph[a] = append(graph[a], b)
				inDegree[b]++
			}
		}
		if b != c {
			if !contains(graph[b], c) {
				graph[b] = append(graph[b], c)
				inDegree[c]++
			}
		}
		if a != c {
			if !contains(graph[a], c) {
				graph[a] = append(graph[a], c)
				inDegree[c]++
			}
		}
	}
	queue := []int{}
	for d, deg := range inDegree {
		if deg == 0 {
			queue = append(queue, d)
		}
	}
	result := []int{}
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		result = append(result, curr)
		for _, next := range graph[curr] {
			inDegree[next]--
			if inDegree[next] == 0 {
				queue = append(queue, next)
			}
		}
	}
	if len(result) != len(digits) {
		panic("cycle")
	}
	s := ""
	for _, d := range result {
		s += strconv.Itoa(d)
	}
	return s
}

func contains(slice []int, val int) bool {
	for _, v := range slice {
		if v == val {
			return true
		}
	}
	return false
}

func main() {
	fmt.Println(passcodeDerivation())
}