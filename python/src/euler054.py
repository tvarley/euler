# Problem 54: Poker Hands
# In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
# High Card: Highest value card.
# One Pair: Two cards of the same value.
# Two Pairs: Two different pairs.
# Three of a Kind: Three cards of the same value.
# Straight: All cards are consecutive values.
# Flush: All cards of the same suit.
# Full House: Three of a kind and a pair.
# Four of a Kind: Four cards of the same value.
# Straight Flush: All cards are consecutive values of same suit.
# Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
# The cards are valued in the order:
# 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
# If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
# Consider the following five hands dealt to two players:
# Hand Player 1 Player 2 Winner
# 1 5H 5C 6S 7S KD Pair of Fives 2C 3S 8S 8D TD Pair of Eights Player 2
# 2 5D 8C 9S JS AC Highest card Ace 2C 5C 7D 8S QH Highest card Queen Player 1
# 3 2D 9C AS AH AC Three Aces 3D 6D 7D TD QD Flush with Diamonds Player 2
# 4 4D 6S 9H QH QC Pair of Queens Highest card Nine 3D 6D 7H QD QS Pair of Queens Highest card Seven Player 1
# 5 2H 2D 4C 4D 4S Full House With Three Fours 3C 3D 3S 9S 9D Full House with Three Threes Player 1
# The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
# How many hands does Player 1 win?
# Answer: 376
# Execution time: Approximately 0.1 seconds
# Optimizations: Implemented hand ranking with efficient counter-based logic, pre-sorted ranks for comparison.
# Notes: Parsed the provided poker hands data and implemented standard poker ranking rules for accurate comparison.
from collections import Counter

def card_value(card):
    rank = card[0]
    return '23456789TJQKA'.index(rank)

def hand_rank(hand):
    ranks = sorted([card_value(c) for c in hand], reverse=True)
    suits = [c[1] for c in hand]
    is_flush = len(set(suits)) == 1
    rank_counts = Counter(ranks)
    counts = sorted(rank_counts.values(), reverse=True)
    is_straight = ranks == list(range(ranks[0], ranks[0] - 5, -1)) or ranks == [14, 5, 4, 3, 2]
    if is_straight:
        if ranks == [14, 5, 4, 3, 2]:
            ranks = [5, 4, 3, 2, 1]
    if is_straight and is_flush:
        return (8, ranks)
    if counts == [4, 1]:
        four_value = [k for k, v in rank_counts.items() if v == 4][0]
        kicker = [k for k, v in rank_counts.items() if v == 1][0]
        return (7, [four_value, kicker])
    if counts == [3, 2]:
        three_value = [k for k, v in rank_counts.items() if v == 3][0]
        pair_value = [k for k, v in rank_counts.items() if v == 2][0]
        return (6, [three_value, pair_value])
    if is_flush:
        return (5, ranks)
    if is_straight:
        return (4, ranks)
    if counts == [3, 1, 1]:
        three_value = [k for k, v in rank_counts.items() if v == 3][0]
        kickers = sorted([r for r in ranks if r != three_value], reverse=True)
        return (3, [three_value] + kickers)
    if counts == [2, 2, 1]:
        pairs = sorted([k for k, v in rank_counts.items() if v == 2], reverse=True)
        kicker = [k for k, v in rank_counts.items() if v == 1][0]
        return (2, pairs + [kicker])
    if counts == [2, 1, 1, 1]:
        pair_value = [k for k, v in rank_counts.items() if v == 2][0]
        kickers = sorted([r for r in ranks if r != pair_value], reverse=True)
        return (1, [pair_value] + kickers)
    return (0, ranks)

def solve():
    with open('data/p054_poker.txt') as f:
        lines = f.readlines()
    count = 0
    for line in lines:
        cards = line.strip().split()
        p1 = cards[:5]
        p2 = cards[5:]
        r1 = hand_rank(p1)
        r2 = hand_rank(p2)
        if r1 > r2:
            count += 1
    return count