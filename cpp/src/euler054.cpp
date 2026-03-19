// https://projecteuler.net/problem=54

// Poker Hands

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
// If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
// Consider the following five hands dealt to two players:
// The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.
// How many hands does Player 1 win?

// Answer: 376

// Authored by: Tim Varley 💘

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

enum HandType {
    HIGH_CARD = 0,
    ONE_PAIR = 1,
    TWO_PAIRS = 2,
    THREE_KIND = 3,
    STRAIGHT = 4,
    FLUSH = 5,
    FULL_HOUSE = 6,
    FOUR_KIND = 7,
    STRAIGHT_FLUSH = 8,
    ROYAL_FLUSH = 9
};

struct Hand {
    HandType type;
    std::vector<int> ranks; // for tie breaking
};

int card_value(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return 0;
}

Hand evaluate_hand(const std::vector<std::string>& cards) {
    std::vector<int> values;
    std::vector<char> suits;
    for (const auto& card : cards) {
        std::string val_str = (card.size() == 3) ? card.substr(0, 2) : card.substr(0, 1);
        char suit = card.back();
        int val = 0;
        if (val_str.size() == 2 && val_str == "10") val = 10;
        else {
            char c = val_str[0];
            if (c == 'T') val = 10;
            else if (c == 'J') val = 11;
            else if (c == 'Q') val = 12;
            else if (c == 'K') val = 13;
            else if (c == 'A') val = 14;
            else val = c - '0';
        }
        values.push_back(val);
        suits.push_back(suit);
    }
    std::sort(values.begin(), values.end());
    bool is_flush = std::all_of(suits.begin(), suits.end(), [&](char s){ return s == suits[0]; });
    bool is_straight = true;
    for (int i = 1; i < 5; ++i) {
        if (values[i] != values[0] + i) is_straight = false;
    }
    // Special case for A-2-3-4-5 straight
    if (values == std::vector<int>{2,3,4,5,14}) {
        is_straight = true;
        values = {1,2,3,4,5}; // adjust for comparison
    }
    if (is_flush && is_straight) {
        if (values[4] == 14) return {ROYAL_FLUSH, {}};
        return {STRAIGHT_FLUSH, values};
    }
    if (is_flush) return {FLUSH, values};
    if (is_straight) return {STRAIGHT, values};
    // Count frequencies
    std::vector<int> freq(15, 0);
    for (int v : values) ++freq[v];
    std::vector<int> counts;
    for (int i = 14; i >= 2; --i) {
        if (freq[i] > 0) counts.push_back(freq[i]);
    }
    std::sort(counts.rbegin(), counts.rend());
    if (counts == std::vector<int>{4,1}) return {FOUR_KIND, values};
    if (counts == std::vector<int>{3,2}) return {FULL_HOUSE, values};
    if (counts == std::vector<int>{3,1,1}) return {THREE_KIND, values};
    if (counts == std::vector<int>{2,2,1}) return {TWO_PAIRS, values};
    if (counts == std::vector<int>{2,1,1,1}) return {ONE_PAIR, values};
    return {HIGH_CARD, values};
}

bool hand_greater(const Hand& a, const Hand& b) {
    if (a.type != b.type) return a.type > b.type;
    if (a.ranks.empty() && b.ranks.empty()) return false;
    if (a.ranks.empty()) return true;
    if (b.ranks.empty()) return false;
    for (int i = 4; i >= 0; --i) {
        if (a.ranks[i] != b.ranks[i]) return a.ranks[i] > b.ranks[i];
    }
    return false;
}

int poker_hands() {
    std::ifstream file("./src/poker.txt");
    if (!file) return 0;
    std::string line;
    int player1_wins = 0;
    while (std::getline(file, line)) {
        std::vector<std::string> cards;
        std::string card;
        for (char c : line) {
            if (c == ' ') {
                if (!card.empty()) {
                    cards.push_back(card);
                    card.clear();
                }
            } else {
                card += c;
            }
        }
        if (!card.empty()) cards.push_back(card);
        if (cards.size() != 10) continue;
        std::vector<std::string> p1(cards.begin(), cards.begin() + 5);
        std::vector<std::string> p2(cards.begin() + 5, cards.end());
        Hand h1 = evaluate_hand(p1);
        Hand h2 = evaluate_hand(p2);
        if (hand_greater(h1, h2)) ++player1_wins;
    }
    return player1_wins;
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[]) {
    std::cout << poker_hands() << std::endl;
}
#endif // UNITTEST_MODE