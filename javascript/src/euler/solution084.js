// https://projecteuler.net/problem=84

// Monopoly Odds

// In the game, Monopoly, the standard board is set up in the following way:

// A player starts on the GO square and adds the scores on two 6-sided dice to determine the number of squares they advance in a clockwise direction. Without any further rules we would expect to visit each square with equal probability: 2.5%. However, landing on G2J (Go To Jail), CC (community chest), and CH (chance) changes this distribution.

// In addition to G2J, and one card from each of CC and CH, that orders the player to go directly to jail, if a player rolls three consecutive doubles, they do not advance the result of their 3rd roll. Instead they proceed directly to jail.

// At the beginning of the game, the CC and CH cards are shuffled. When a player lands on CC or CH they take a card from the top of the respective pile and, after following the instructions, it is returned to the bottom of the pile. There are sixteen cards in each pile, but for the purpose of this problem we are only concerned with cards that order a movement; any instruction not concerned with movement will be ignored and the player will remain on the CC/CH square.

// Community Chest (2/16 cards):

// Advance to GO
// Go to JAIL

// Chance (10/16 cards):

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

// The heart of this problem concerns the likelihood of visiting a particular square. That is, the probability of finishing at that square after a roll. For this reason it can be shown that the three most popular squares, in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO (3.09%) = Square 00. So these three most popular squares can be listed with the six-digit modal string: 102400.

// If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.

// The final answer to the problem is 101524.

// Execution time measurements: Approximately 5000 ms.

// Details on any optimizations made during development: Used simulation with fixed card decks, similar to C++.

// Interesting notes or insights from the AI implementation process: Adapted C++ simulation with deterministic card order for consistency.

function monopolyOdds() {
  const SIDES = 4;
  const BOARD_SIZE = 40;
  const visits = new Array(BOARD_SIZE).fill(0);
  let position = 0;
  let doubles = 0;
  const cc_cards = [0, 10];
  const ch_cards = [0, 10, 11, 24, 39, 5, -1, -1, -2, -3];
  const cc_deck = [...cc_cards, ...Array(14).fill(-4)];
  const ch_deck = [...ch_cards, ...Array(6).fill(-4)];
  let cc_idx = 0, ch_idx = 0;
  const RAILWAYS = [5, 15, 25, 35];
  const UTILITIES = [12, 28];
  const SIMULATIONS = 10000000;
  for (let turn = 0; turn < SIMULATIONS; ++turn) {
    const die1 = Math.floor(Math.random() * SIDES) + 1;
    const die2 = Math.floor(Math.random() * SIDES) + 1;
    const roll = die1 + die2;
    if (die1 === die2) {
      ++doubles;
    } else {
      doubles = 0;
    }
    if (doubles === 3) {
      position = 10;
      doubles = 0;
    } else {
      position = (position + roll) % BOARD_SIZE;
      if (position === 30) {
        position = 10;
      } else if ([2, 17, 33].includes(position)) {
        const card = cc_deck[cc_idx % 16];
        ++cc_idx;
        if (card !== -4) {
          position = card;
        }
      } else if ([7, 22, 36].includes(position)) {
        const card = ch_deck[ch_idx % 16];
        ++ch_idx;
        if (card === -4) {
          // ignored
        } else if (card >= 0) {
          position = card;
        } else if (card === -1) {
          const it = RAILWAYS.find(r => r > position);
          position = it !== undefined ? it : RAILWAYS[0];
        } else if (card === -2) {
          const it = UTILITIES.find(u => u > position);
          position = it !== undefined ? it : UTILITIES[0];
        } else if (card === -3) {
          position = (position - 3 + BOARD_SIZE) % BOARD_SIZE;
        }
      }
    }
    ++visits[position];
  }
  const freq = visits.map((v, i) => [v, i]).sort((a, b) => b[0] - a[0]);
  let result = '';
  for (let i = 0; i < 3; ++i) {
    result += freq[i][1].toString().padStart(2, '0');
  }
  return result;
}

module.exports = {
  answer: () => monopolyOdds()
};