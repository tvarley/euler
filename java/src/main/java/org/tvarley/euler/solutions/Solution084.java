// https://projecteuler.net/problem=84
// Monopoly Odds
//
// In the game, Monopoly, the standard board is set up in the following way:
//
// A player starts on the GO square and adds the scores on two 6-sided dice to determine the number of squares they advance in a clockwise direction. Without any further rules we would expect to visit each square with equal probability: 2.5%. However, landing on G2J (Go To Jail), CC (community chest), and CH (chance) changes this distribution.
//
// In addition to G2J, and one card from each of CC and CH, that orders the player to go directly to jail, if a player rolls three consecutive doubles, they do not advance the result of their 3rd roll. Instead they proceed directly to jail.
//
// At the beginning of the game, the CC and CH cards are shuffled. When a player lands on CC or CH they take a card from the top of the respective pile and, after following the instructions, it is returned to the bottom of the pile. There are sixteen cards in each pile, but for the purpose of this problem we are only concerned with cards that order a movement; any instruction not concerned with movement will be ignored and the player will remain on the CC/CH square.
//
// Community Chest (2/16 cards):
//
// Advance to GO
// Go to JAIL
//
// Chance (10/16 cards):
//
// Advance to GO
// Go to JAIL
// Go to C1
// Go to E3
// Go to H2
// Go to R1
// Go to next R (railway company)
// Go to next R
// Go to next U (utility company)
// Go back 3 squares
//
// The heart of this problem concerns the likelihood of visiting a particular square. That is, the probability of finishing at that square after a roll. For this reason it should be clear that, with the exception of G2J for which the probability of finishing on it is zero, the CH squares will have the lowest probabilities, as 5/8 request a movement to another square, and it is the final square that the player finishes at on each roll that we are interested in.
//
// We shall make no distinction between "Just Visiting" and being sent to JAIL, and we shall also ignore the rule about requiring a double to "get out of jail", assuming that they pay to get out on their next turn.
//
// By starting at GO and numbering the squares sequentially from 00 to 39 we can concatenate these two-digit numbers to produce strings that correspond with sets of squares.
//
// Statistically it can be shown that the three most popular squares, in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO (3.09%) = Square 00. So these three most popular squares can be listed with the six-digit modal string: 102400.
//
// If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.
//
// Answer: 101524
//
// Completed on: 2024-12-04
// Time: ~500ms
// Optimizations: Monte Carlo simulation with 10 million turns
// Notes: Shuffled decks with fixed seed. Used Random for dice rolls.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Solution084 implements Solution {
    public String solve() {
        final int SIDES = 4;
        final int BOARD_SIZE = 40;
        final int SIMULATIONS = 10000000;
        int[] visits = new int[BOARD_SIZE];
        int position = 0;
        int doubles = 0;
        List<Integer> ccCards = new ArrayList<>(Arrays.asList(0, 10));
        for (int i = 0; i < 14; ++i) ccCards.add(-4); // ignored
        List<Integer> chCards = new ArrayList<>(Arrays.asList(0, 10, 11, 24, 39, 5, -1, -1, -2, -3));
        for (int i = 0; i < 6; ++i) chCards.add(-4); // ignored
        List<Integer> ccDeck = new ArrayList<>(ccCards);
        List<Integer> chDeck = new ArrayList<>(chCards);
        Random rand = new Random(42);
        Collections.shuffle(ccDeck, rand);
        Collections.shuffle(chDeck, rand);
        int ccIdx = 0, chIdx = 0;
        int[] railways = {5, 15, 25, 35};
        int[] utilities = {12, 28};
        for (int turn = 0; turn < SIMULATIONS; ++turn) {
            int die1 = rand.nextInt(SIDES) + 1;
            int die2 = rand.nextInt(SIDES) + 1;
            int roll = die1 + die2;
            if (die1 == die2) {
                ++doubles;
            } else {
                doubles = 0;
            }
            if (doubles == 3) {
                position = 10; // JAIL
                doubles = 0;
            } else {
                position = (position + roll) % BOARD_SIZE;
                if (position == 30) { // G2J
                    position = 10;
                } else if (position == 2 || position == 17 || position == 33) { // CC
                    int card = ccDeck.get(ccIdx % 16);
                    ++ccIdx;
                    if (card != -4) {
                        position = card;
                    }
                } else if (position == 7 || position == 22 || position == 36) { // CH
                    int card = chDeck.get(chIdx % 16);
                    ++chIdx;
                    if (card == -4) {
                        // ignored
                    } else if (card >= 0) {
                        position = card;
                    } else if (card == -1) { // next R
                        position = nextRailway(position, railways);
                    } else if (card == -2) { // next U
                        position = nextUtility(position, utilities);
                    } else if (card == -3) { // back 3
                        position = (position - 3 + BOARD_SIZE) % BOARD_SIZE;
                    }
                }
            }
            ++visits[position];
        }
        List<int[]> freq = new ArrayList<>();
        for (int i = 0; i < BOARD_SIZE; ++i) {
            freq.add(new int[]{visits[i], i});
        }
        freq.sort((a, b) -> Integer.compare(b[0], a[0]));
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 3; ++i) {
            result.append(String.format("%02d", freq.get(i)[1]));
        }
        return result.toString();
    }

    private int nextRailway(int pos, int[] railways) {
        for (int r : railways) {
            if (r > pos) return r;
        }
        return railways[0];
    }

    private int nextUtility(int pos, int[] utilities) {
        for (int u : utilities) {
            if (u > pos) return u;
        }
        return utilities[0];
    }
}