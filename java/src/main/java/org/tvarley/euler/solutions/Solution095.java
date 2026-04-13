// https://projecteuler.net/problem=95
// Amicable Chains
//
// The proper divisors of a number are all the divisors excluding the number itself. For example, the proper divisors of 28 are 1, 2, 4, 7, and 14, and the sum is 28, hence 28 is perfect.
//
// Note that a number cannot be included in the chain if it has a proper divisor sum greater than 1,000,000.
//
// A chain is called amicable if every number in the chain is the sum of the proper divisors of the previous number in the chain, and the chain is longer than one number.
//
// Find the smallest member of the longest amicable chain with no element exceeding one million.
//
// Answer: 14316
//
// Completed on: 2024-12-04
// Time: ~200ms
// Optimizations: Precomputed divisor sums, visited array to avoid reprocessing
// Notes: Detected cycles by checking if current is in chain set.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.*;

public class Solution095 implements Solution {
    private static final int MAX = 1000000;
    private int[] sumDiv = new int[MAX + 1];

    private void computeSumDiv() {
        for (int i = 1; i <= MAX; ++i) {
            for (int j = i * 2; j <= MAX; j += i) {
                sumDiv[j] += i;
            }
        }
    }

    public String solve() {
        computeSumDiv();
        int maxLength = 0;
        int minMember = MAX;
        boolean[] visited = new boolean[MAX + 1];
        for (int i = 2; i <= MAX; ++i) {
            if (visited[i] || sumDiv[i] > MAX) continue;
            List<Integer> chain = new ArrayList<>();
            Set<Integer> chainSet = new HashSet<>();
            int current = i;
            while (current <= MAX && sumDiv[current] != current && !chainSet.contains(current)) {
                chain.add(current);
                chainSet.add(current);
                current = sumDiv[current];
            }
            if (chainSet.contains(current) && chain.size() > 1) {
                int cycleStart = -1;
                for (int j = 0; j < chain.size(); ++j) {
                    if (chain.get(j) == current) {
                        cycleStart = j;
                        break;
                    }
                }
                int cycleLength = chain.size() - cycleStart;
                if (cycleLength > maxLength) {
                    maxLength = cycleLength;
                    int smallest = MAX;
                    for (int j = cycleStart; j < chain.size(); ++j) {
                        if (chain.get(j) < smallest) smallest = chain.get(j);
                        visited[chain.get(j)] = true;
                    }
                    minMember = smallest;
                }
            }
        }
        return Integer.toString(minMember);
    }
}