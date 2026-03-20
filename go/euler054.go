// https://projecteuler.net/problem=54
//
// Poker Hands
//
// In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
// High Card: Highest value card.
// One Pair: Two cards of the same value.
// Two Pairs: Two different pairs.
// Three of a Kind: Three cards of the same value.
// Straight: All cards are consecutive values.
// Flush: All cards of the same suit.
// Full House: Three of a kind and a pair.
// Four of a Kind: Four cards of the same value.
// Straight Flush: All cards are consecutive values of same suit.
// Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
// The cards are valued in the order:2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
// If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below).
// But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
// Consider the following five hands dealt to two players: [examples]
// The file, poker.txt, contains one-thousand random hands dealt to two players.
// Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards.
// You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
// How many hands does Player 1 win?
//
// Answer: 376

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Card struct {
	value int
	suit  byte
}

type Hand []Card

func (h Hand) Len() int           { return len(h) }
func (h Hand) Less(i, j int) bool { return h[i].value < h[j].value }
func (h Hand) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func parseCard(s string) Card {
	var v int
	switch s[0] {
	case 'T':
		v = 10
	case 'J':
		v = 11
	case 'Q':
		v = 12
	case 'K':
		v = 13
	case 'A':
		v = 14
	default:
		v, _ = strconv.Atoi(string(s[0]))
	}
	return Card{value: v, suit: s[1]}
}

func evaluateHand(h Hand) (rank int, tiebreak []int) {
	sort.Sort(h)
	values := make([]int, 5)
	suits := make([]byte, 5)
	for i, c := range h {
		values[i] = c.value
		suits[i] = c.suit
	}

	// Check for flush
	isFlush := true
	for i := 1; i < 5; i++ {
		if suits[i] != suits[0] {
			isFlush = false
			break
		}
	}

	// Check for straight
	isStraight := true
	for i := 1; i < 5; i++ {
		if values[i] != values[i-1]+1 {
			isStraight = false
			break
		}
	}
	// Special case: A2345
	if values[0] == 2 && values[1] == 3 && values[2] == 4 && values[3] == 5 && values[4] == 14 {
		isStraight = true
		sort.Ints(values) // now 2,3,4,5,14 but for tiebreak, use 5 as high
		values[4] = 5    // treat as 5 high
	}

	if isStraight && isFlush {
		if values[4] == 14 && values[0] == 10 {
			return 9, []int{14} // royal flush
		}
		return 8, []int{values[4]} // straight flush
	}

	// Count frequencies
	counts := make(map[int]int)
	for _, v := range values {
		counts[v]++
	}

	var pairs []int
	var three, four int
	for v, c := range counts {
		switch c {
		case 2:
			pairs = append(pairs, v)
		case 3:
			three = v
		case 4:
			four = v
		}
	}
	sort.Sort(sort.Reverse(sort.IntSlice(pairs)))

	if four > 0 {
		return 7, []int{four, values[0] + values[1] + values[2] + values[3] + values[4] - 4*four} // four of a kind, kicker
	}

	if three > 0 && len(pairs) > 0 {
		return 6, []int{three, pairs[0]} // full house
	}

	if isFlush {
		return 5, values // flush, all cards
	}

	if isStraight {
		return 4, []int{values[4]} // straight
	}

	if three > 0 {
		kicker := 0
		for _, v := range values {
			if v != three {
				if v > kicker {
					kicker = v
				}
			}
		}
		return 3, []int{three, kicker} // three of a kind
	}

	if len(pairs) == 2 {
		kicker := 0
		for _, v := range values {
			if counts[v] == 1 && v > kicker {
				kicker = v
			}
		}
		return 2, []int{pairs[0], pairs[1], kicker} // two pairs
	}

	if len(pairs) == 1 {
		var kickers []int
		for _, v := range values {
			if counts[v] == 1 {
				kickers = append(kickers, v)
			}
		}
		sort.Sort(sort.Reverse(sort.IntSlice(kickers)))
		return 1, append([]int{pairs[0]}, kickers...) // pair
	}

	// high card
	sort.Sort(sort.Reverse(sort.IntSlice(values)))
	return 0, values
}

func compareHands(h1, h2 Hand) int {
	r1, tb1 := evaluateHand(h1)
	r2, tb2 := evaluateHand(h2)
	if r1 > r2 {
		return 1
	}
	if r1 < r2 {
		return -1
	}
	for i := 0; i < len(tb1) && i < len(tb2); i++ {
		if tb1[i] > tb2[i] {
			return 1
		}
		if tb1[i] < tb2[i] {
			return -1
		}
	}
	return 0 // should not happen
}

func main() {
	file, err := os.Open("p054_poker.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	count := 0
	for scanner.Scan() {
		line := strings.Fields(scanner.Text())
		h1 := make(Hand, 5)
		h2 := make(Hand, 5)
		for i := 0; i < 5; i++ {
			h1[i] = parseCard(line[i])
			h2[i] = parseCard(line[i+5])
		}
		if compareHands(h1, h2) > 0 {
			count++
		}
	}
	fmt.Println(count)
}