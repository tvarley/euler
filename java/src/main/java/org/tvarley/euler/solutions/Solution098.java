// https://projecteuler.net/problem=98
// Anagramic Squares
//
// By replacing each of the letters in the word CARE with 1, 2, 9, and 6 respectively, we form a square number: 1296 = 36^2. What is remarkable is that, by using the same digital substitutions, the anagram, RACE, also forms a square number: 9216 = 96^2. We shall call CARE (and RACE) a square anagram word pair and specify further that leading zeroes are not permitted, neither may a different letter have the same digital value as another letter.
//
// Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, find all the square anagram word pairs (a palindromic square is NOT considered to be an anagram of itself).
//
// What is the largest square number formed by any member of such a pair? NOTE: All anagrams formed must be contained in the given text file.
//
// Answer: 18769
//
// Completed on: 2024-12-04
// Time: ~100ms
// Optimizations: Backtracking digit assignment, grouped by sorted letters
// Notes: Parsed words from file, checked pairs for square anagrams.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution098 implements Solution {
    private boolean isSquare(long n) {
        long root = (long) Math.sqrt(n);
        return root * root == n;
    }

    private void tryMapping(List<Character> letterList, int pos, boolean[] used, Map<Character, Integer> mapping, String w1, String w2, long[] maxSquare) {
        if (pos == letterList.size()) {
            if (mapping.get(w1.charAt(0)) == 0 || mapping.get(w2.charAt(0)) == 0) return;
            long num1 = 0, num2 = 0;
            for (char c : w1.toCharArray()) num1 = num1 * 10 + mapping.get(c);
            for (char c : w2.toCharArray()) num2 = num2 * 10 + mapping.get(c);
            if (isSquare(num1) && isSquare(num2)) {
                maxSquare[0] = Math.max(maxSquare[0], Math.max(num1, num2));
            }
            return;
        }
        for (int d = 0; d < 10; ++d) {
            if (used[d]) continue;
            mapping.put(letterList.get(pos), d);
            used[d] = true;
            tryMapping(letterList, pos + 1, used, mapping, w1, w2, maxSquare);
            used[d] = false;
        }
    }

    public String solve() {
        List<String> words = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                getClass().getResourceAsStream("/p098_words.txt")))) {
            String line = br.readLine();
            StringBuilder word = new StringBuilder();
            boolean inQuote = false;
            for (char c : line.toCharArray()) {
                if (c == '"') {
                    inQuote = !inQuote;
                    if (!inQuote && word.length() > 0) {
                        words.add(word.toString());
                        word.setLength(0);
                    }
                } else if (inQuote) {
                    word.append(c);
                }
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Map<String, List<String>> anagrams = new HashMap<>();
        for (String w : words) {
            char[] chars = w.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            anagrams.computeIfAbsent(sorted, k -> new ArrayList<>()).add(w);
        }
        long[] maxSquare = {0};
        for (List<String> group : anagrams.values()) {
            if (group.size() < 2) continue;
            for (int i = 0; i < group.size(); ++i) {
                for (int j = i + 1; j < group.size(); ++j) {
                    String w1 = group.get(i), w2 = group.get(j);
                    Set<Character> letters = new HashSet<>();
                    for (char c : w1.toCharArray()) letters.add(c);
                    for (char c : w2.toCharArray()) letters.add(c);
                    if (letters.size() > 10) continue;
                    List<Character> letterList = new ArrayList<>(letters);
                    boolean[] used = new boolean[10];
                    Map<Character, Integer> mapping = new HashMap<>();
                    tryMapping(letterList, 0, used, mapping, w1, w2, maxSquare);
                }
            }
        }
        return Long.toString(maxSquare[0]);
    }
}