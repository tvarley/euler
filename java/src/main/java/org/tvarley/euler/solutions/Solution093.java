// https://projecteuler.net/problem=93
// Arithmetic Expressions
//
// By using each of the digits from the set, {1, 2, 3, 4}, exactly once, and making use of the four arithmetic operations (+, −, *, /) and brackets/parentheses, it is possible to form different positive integer targets.
//
// For example, 8 can be made in three ways: 8 = (4*(2+3+1)), 8 = (4*2*3/1), 8 = (4/2*3*1), but 8 = 4*(2+3+1) is not acceptable as it uses the digits in order but not exactly once each.
//
// Although the set {1, 2, 3, 4} only produces the positive integers 1 through 28, the set {1, 2, 5, 8} produces 1 through 33.
//
// Find the set of four distinct digits, a < b < c < d, for which the longest set of consecutive positive integers, 1 to n, can be obtained, and give your answer as a string: abcd.
//
// Answer: 1258
//
// Completed on: 2024-12-04
// Time: ~1000ms
// Optimizations: Recursive evaluation with memoization not needed
// Notes: Generated all permutations and expressions recursively.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.*;

public class Solution093 implements Solution {
    private Set<Double> evaluateRec(List<Double> nums) {
        int n = nums.size();
        Set<Double> results = new HashSet<>();
        if (n == 1) {
            results.add(nums.get(0));
            return results;
        }
        for (int i = 1; i < n; ++i) {
            List<Double> left = nums.subList(0, i);
            List<Double> right = nums.subList(i, n);
            Set<Double> leftVals = evaluateRec(left);
            Set<Double> rightVals = evaluateRec(right);
            for (double lv : leftVals) {
                for (double rv : rightVals) {
                    results.add(lv + rv);
                    results.add(lv - rv);
                    results.add(lv * rv);
                    if (rv != 0) results.add(lv / rv);
                }
            }
        }
        return results;
    }

    private Set<Integer> evaluate(List<Double> nums) {
        Set<Double> doubles = evaluateRec(nums);
        Set<Integer> ints = new HashSet<>();
        for (double d : doubles) {
            if (d > 0 && d == (int) d) ints.add((int) d);
        }
        return ints;
    }

    private List<List<Integer>> generatePermutations(List<Integer> set) {
        List<List<Integer>> perms = new ArrayList<>();
        if (set.size() == 1) {
            perms.add(new ArrayList<>(set));
            return perms;
        }
        for (int i = 0; i < set.size(); ++i) {
            int num = set.get(i);
            List<Integer> remaining = new ArrayList<>(set);
            remaining.remove(i);
            List<List<Integer>> subPerms = generatePermutations(remaining);
            for (List<Integer> sub : subPerms) {
                List<Integer> perm = new ArrayList<>();
                perm.add(num);
                perm.addAll(sub);
                perms.add(perm);
            }
        }
        return perms;
    }

    public String solve() {
        int[] digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int maxN = 0;
        String bestSet = "";
        for (int a = 0; a < 9; ++a) {
            for (int b = a + 1; b < 9; ++b) {
                for (int c = b + 1; c < 9; ++c) {
                    for (int d = c + 1; d < 9; ++d) {
                        List<Integer> set = Arrays.asList(digits[a], digits[b], digits[c], digits[d]);
                        Set<Integer> values = new HashSet<>();
                        List<List<Integer>> perms = generatePermutations(set);
                        for (List<Integer> perm : perms) {
                            List<Double> nums = new ArrayList<>();
                            for (int num : perm) nums.add((double) num);
                            Set<Integer> res = evaluate(nums);
                            values.addAll(res);
                        }
                        int n = 0;
                        while (values.contains(n + 1)) n++;
                        if (n > maxN) {
                            maxN = n;
                            bestSet = "" + set.get(0) + set.get(1) + set.get(2) + set.get(3);
                        }
                    }
                }
            }
        }
        return bestSet;
    }
}