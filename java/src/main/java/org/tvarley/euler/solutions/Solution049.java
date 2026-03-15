/*
 * Solution for Euler problem 049
 *
 * Prime Permutations
 *
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
 * What 12-digit number do you form by concatenating the three terms in this sequence?
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;
import java.util.*;

public class Solution049 implements Solution {
  public String solve() {
    for (int a = 1000; a < 10000; a++) {
      if (!Prime.isPrime(a)) continue;
      String sa = String.valueOf(a);
      char[] chars = sa.toCharArray();
      Arrays.sort(chars);
      String sorted = new String(chars);
      List<Integer> perms = new ArrayList<>();
      for (int p : generatePrimes(sorted)) {
        if (String.valueOf(p).length() == 4) perms.add(p);
      }
      Collections.sort(perms);
      for (int i = 0; i < perms.size(); i++) {
        for (int j = i + 1; j < perms.size(); j++) {
          int diff = perms.get(j) - perms.get(i);
          int third = perms.get(j) + diff;
          if (perms.contains(third) && third != perms.get(i) && perms.get(i) != 1487) {
            return "" + perms.get(i) + perms.get(j) + third;
          }
        }
      }
    }
    return "";
  }

  private List<Integer> generatePrimes(String sorted) {
    Set<Integer> primes = new HashSet<>();
    permute(sorted.toCharArray(), 0, primes);
    return new ArrayList<>(primes);
  }

  private void permute(char[] arr, int index, Set<Integer> result) {
    if (index == arr.length) {
      int num = Integer.parseInt(new String(arr));
      if (Prime.isPrime(num)) result.add(num);
      return;
    }
    Set<Character> used = new HashSet<>();
    for (int i = index; i < arr.length; i++) {
      if (used.add(arr[i])) {
        swap(arr, index, i);
        permute(arr, index + 1, result);
        swap(arr, index, i);
      }
    }
  }

  private void swap(char[] arr, int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}