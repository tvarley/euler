// https://projecteuler.net/problem=54
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

use std::fs;

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct Card {
    rank: u8, // 2-14
    suit: u8, // 0-3
}

impl Card {
    fn new(s: &str) -> Self {
        let chars: Vec<char> = s.chars().collect();
        let rank = match chars[0] {
            '2'..='9' => chars[0].to_digit(10).unwrap() as u8,
            'T' => 10,
            'J' => 11,
            'Q' => 12,
            'K' => 13,
            'A' => 14,
            _ => panic!("Invalid rank"),
        };
        let suit = match chars[1] {
            'C' => 0,
            'D' => 1,
            'H' => 2,
            'S' => 3,
            _ => panic!("Invalid suit"),
        };
        Card { rank, suit }
    }
}

fn evaluate_hand(hand: &[Card]) -> (u8, Vec<u8>) {
    let mut sorted = hand.to_vec();
    sorted.sort_by(|a, b| b.rank.cmp(&a.rank));
    let ranks: Vec<u8> = sorted.iter().map(|c| c.rank).collect();
    let suits: Vec<u8> = sorted.iter().map(|c| c.suit).collect();
    let flush = suits.iter().all(|&s| s == suits[0]);

    let mut rank_counts = [0u8; 15];
    for &r in &ranks {
        rank_counts[r as usize] += 1;
    }
    let mut counts: Vec<(u8, u8)> = (2..=14).map(|r| (rank_counts[r as usize], r)).collect();
    counts.sort_by(|a, b| b.0.cmp(&a.0).then(b.1.cmp(&a.1)));

    let straight = is_straight(&ranks);
    let straight_high = if straight {
        if ranks[0] == 14 && ranks[4] == 2 { 5 } else { ranks[0] }
    } else { 0 };

    if flush && straight && ranks[0] == 14 && ranks[4] == 10 {
        // Royal Flush
        (9, vec![])
    } else if flush && straight {
        // Straight Flush
        (8, vec![straight_high])
    } else if counts[0].0 == 4 {
        // Four of a Kind
        (7, vec![counts[0].1, counts[1].1])
    } else if counts[0].0 == 3 && counts[1].0 == 2 {
        // Full House
        (6, vec![counts[0].1, counts[1].1])
    } else if flush {
        // Flush
        (5, ranks.clone())
    } else if straight {
        // Straight
        (4, vec![straight_high])
    } else if counts[0].0 == 3 {
        // Three of a Kind
        let three_rank = counts[0].1;
        let mut kickers: Vec<u8> = ranks.iter().filter(|&r| *r != three_rank).cloned().collect();
        kickers.sort_by(|a, b| b.cmp(a));
        let mut tie = vec![three_rank];
        tie.extend(kickers);
        (3, tie)
    } else if counts[0].0 == 2 && counts[1].0 == 2 {
        // Two Pairs
        let pair1 = counts[0].1;
        let pair2 = counts[1].1;
        let kicker = counts[2].1;
        (2, vec![pair1.max(pair2), pair1.min(pair2), kicker])
    } else if counts[0].0 == 2 {
        // One Pair
        let pair_rank = counts[0].1;
        let mut kickers: Vec<u8> = ranks.iter().filter(|&r| *r != pair_rank).cloned().collect();
        kickers.sort_by(|a, b| b.cmp(a));
        let mut tie = vec![pair_rank];
        tie.extend(kickers);
        (1, tie)
    } else {
        // High Card
        (0, ranks.clone())
    }
}

fn is_straight(ranks: &[u8]) -> bool {
    // ranks are sorted descending
    if ranks[0] == 14 && ranks[1] == 5 && ranks[2] == 4 && ranks[3] == 3 && ranks[4] == 2 {
        true
    } else {
        ranks.windows(2).all(|w| w[0] == w[1] + 1)
    }
}

pub fn poker_hands() -> u32 {
    let content = fs::read_to_string("poker.txt").expect("Failed to read poker.txt");
    let mut count = 0;
    for line in content.lines() {
        let cards: Vec<Card> = line.split_whitespace().map(Card::new).collect();
        assert_eq!(cards.len(), 10);
        let p1 = &cards[0..5];
        let p2 = &cards[5..10];
        let eval1 = evaluate_hand(p1);
        let eval2 = evaluate_hand(p2);
        if eval1 > eval2 {
            count += 1;
        }
    }
    count
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn euler_054() {
        assert_eq!(poker_hands(), 376);
    }
}
