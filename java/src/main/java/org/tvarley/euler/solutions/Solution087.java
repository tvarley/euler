// https://projecteuler.net/problem=87
// Prime Power Triples
//
// Find the number of numbers below fifty million that can be expressed as the sum of a prime square, prime cube, and prime fourth power.
//
// Answer: 1097343
//
// Completed on: 2024-12-04
// Time: ~100ms
// Optimizations: Sieve for primes, nested loops with early breaks
// Notes: Used HashSet to store unique sums.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.util.HashSet;
import java.util.Set;

public class Solution087 implements Solution {
    private boolean[] isPrime;
    private int maxPrime;

    public String solve() {
        final long LIMIT = 50000000;
        maxPrime = 0;
        while ((long) maxPrime * maxPrime < LIMIT) maxPrime++;
        maxPrime--;
        generatePrimes(maxPrime);
        Set<Long> numbers = new HashSet<>();
        for (int p4 = 2; isPrime[p4]; ++p4) {
            long fourth = (long) p4 * p4 * p4 * p4;
            if (fourth >= LIMIT) break;
            for (int p3 = 2; isPrime[p3]; ++p3) {
                long cube = (long) p3 * p3 * p3;
                if (fourth + cube >= LIMIT) break;
                for (int p2 = 2; isPrime[p2]; ++p2) {
                    long square = (long) p2 * p2;
                    long sum = fourth + cube + square;
                    if (sum >= LIMIT) break;
                    numbers.add(sum);
                }
            }
        }
        return Long.toString(numbers.size());
    }

    private void generatePrimes(int maxN) {
        isPrime = new boolean[maxN + 1];
        for (int i = 2; i <= maxN; ++i) {
            isPrime[i] = true;
        }
        for (long i = 2; i <= maxN; ++i) {
            if (isPrime[(int) i]) {
                for (long j = i * i; j <= maxN; j += i) {
                    isPrime[(int) j] = false;
                }
            }
        }
    }
}