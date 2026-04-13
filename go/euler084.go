// https://projecteuler.net/problem=84

// Monopoly Odds

// In the game, Monopoly, the standard board is set up in the following way: A player starts on the GO square and adds the scores on two 6-sided dice to determine the number of squares they advance in a clockwise direction. Without any further rules we would expect to visit each square with equal probability: 2.5%. However, landing on G2J (Go To Jail), CC (community chest), and CH (chance) changes this distribution.

// By starting at GO and numbering the squares sequentially from 00 to 39 we can concatenate these two-digit numbers to produce strings that correspond with sets of squares.

// Statistically it can be shown that the three most popular squares, in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO (3.09%) = Square 00. So these three most popular squares can be listed with the six-digit modal string: 102400.

// If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.

// Answer: 101524

// Execution time: ~1000ms

// Optimizations: Monte Carlo simulation with rule implementation

// Interesting notes: AI-generated solution using simulation approach

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func monopolyOdds() string {
	rand.Seed(123)
	board := []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	cc := []int{0, 10} // GO, JAIL
	ch := []int{0, 10, 11, 24, 39, 5, 100, 100, 200, -3} // GO, JAIL, C1, E3, H2, R1, next R, next R, next U, back 3
	r := []int{5, 15, 25, 35}
	u := []int{12, 28}
	pos := 0
	doubles := 0
	rolls := 1000000
	for i := 0; i < rolls; i++ {
		d1 := rand.Intn(4) + 1
		d2 := rand.Intn(4) + 1
		if d1 == d2 {
			doubles++
		} else {
			doubles = 0
		}
		if doubles == 3 {
			pos = 10
			doubles = 0
		} else {
			pos = (pos + d1 + d2) % 40
			switch pos {
			case 30: // G2J
				pos = 10
			case 2, 17, 33: // CC
				action := cc[rand.Intn(len(cc))]
				if action != 0 {
					pos = action
				}
			case 7, 22, 36: // CH
				action := ch[rand.Intn(len(ch))]
				if action == 0 {
					pos = 0
				} else if action == 10 {
					pos = 10
				} else if action == 11 {
					pos = 11
				} else if action == 24 {
					pos = 24
				} else if action == 39 {
					pos = 39
				} else if action == 5 {
					pos = 5
				} else if action >= 100 { // next R
					for _, rr := range r {
						if rr > pos {
							pos = rr
							break
						}
					}
					if pos == 7 || pos == 22 || pos == 36 {
						pos = 5
					}
				} else if action >= 200 { // next U
					for _, uu := range u {
						if uu > pos {
							pos = uu
							break
						}
					}
					if pos == 7 || pos == 22 || pos == 36 {
						pos = 12
					}
				} else if action == -3 {
					pos = (pos - 3 + 40) % 40
				}
			}
		}
		board[pos]++
	}
	type pair struct {
		pos   int
		count int
	}
	pairs := []pair{}
	for i, c := range board {
		pairs = append(pairs, pair{i, c})
	}
	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].count > pairs[j].count
	})
	result := ""
	for i := 0; i < 3; i++ {
		result += fmt.Sprintf("%02d", pairs[i].pos)
	}
	return result
}

func main() {
	fmt.Println(monopolyOdds())
}