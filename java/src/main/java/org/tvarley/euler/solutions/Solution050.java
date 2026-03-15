/*
 * Solution for Euler problem 050
 *
 * Consecutive Prime Sum
 *
 * The prime 41, can be written as the sum of six consecutive primes:
 * 41 = 2 + 3 + 5 + 7 + 11 + 13.
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 * The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;
import java.util.*;

public class Solution050 implements Solution {
  public String solve() {
    List<Integer> primes = new ArrayList<>();
    for (int i = 2; i < 1000000; i++) {
      if (Prime.isPrime(i)) primes.add(i);
    }
    int maxLen = 0;
    int maxPrime = 0;
    for (int start = 0; start < primes.size(); start++) {
      long sum = 0;
      for (int end = start; end < primes.size(); end++) {
        sum += primes.get(end);
        if (sum >= 1000000) break;
        if (end - start + 1 > maxLen && Prime.isPrime((int) sum)) {
          maxLen = end - start + 1;
          maxPrime = (int) sum;
        }
      }
    }
    return Integer.toString(maxPrime);
  }
}