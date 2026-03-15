// https://projecteuler.net/problem=49

/*

Prime Permutations

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

Answer: 296962999629

*/

package main

import "fmt"

import "sort"

import "strconv"

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func permutations(arr []int, start int, result *[]int) {
	if start == len(arr)-1 {
		num := 0
		for _, d := range arr {
			num = num*10 + d
		}
		*result = append(*result, num)
		return
	}
	for i := start; i < len(arr); i++ {
		arr[start], arr[i] = arr[i], arr[start]
		permutations(arr, start+1, result)
		arr[start], arr[i] = arr[i], arr[start]
	}
}

func main() {
	primes := []int{}
	for i := 1000; i < 10000; i++ {
		if isPrime(i) {
			primes = append(primes, i)
		}
	}
	permMap := make(map[string][]int)
	for _, p := range primes {
		s := strconv.Itoa(p)
		runes := []rune(s)
		sort.Sort(sortRunes(runes))
		key := string(runes)
		permMap[key] = append(permMap[key], p)
	}
	var sequences [][]int
	for _, group := range permMap {
		if len(group) >= 3 {
			sort.Ints(group)
			for i := 0; i < len(group)-2; i++ {
				for j := i + 1; j < len(group)-1; j++ {
					diff := group[j] - group[i]
					if group[j]+diff < 10000 && contains(group, group[j]+diff) {
						sequences = append(sequences, []int{group[i], group[j], group[j]+diff})
					}
				}
			}
		}
	}
	// Find the sequence not starting with 1487
	for _, seq := range sequences {
		if seq[0] != 1487 {
			fmt.Printf("%d%d%d\n", seq[0], seq[1], seq[2])
			return
		}
	}
}

type sortRunes []rune

func (s sortRunes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s sortRunes) Len() int {
	return len(s)
}

func contains(arr []int, val int) bool {
	for _, v := range arr {
		if v == val {
			return true
		}
	}
	return false
}