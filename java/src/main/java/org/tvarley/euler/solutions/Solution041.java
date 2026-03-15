/*
 * Solution for Euler problem 041
 *
 * Pandigital Prime
 *
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.
 * What is the largest n-digit pandigital prime that exists?
 *
 * @author tvarley
 * @date 3/14/2026
 */
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import org.tvarley.euler.util.Prime;
import java.util.ArrayList;
import java.util.List;

public class Solution041 implements Solution {
  public String solve() {
    String digits = "1234567";
    List<String> perms = generatePermutations(digits);
    long max = 0;
    for (String p : perms) {
      long num = Long.parseLong(p);
      if (Prime.isPrime((int) num)) {
        if (num > max) max = num;
      }
    }
    return Long.toString(max);
  }

  private List<String> generatePermutations(String s) {
    List<String> result = new ArrayList<>();
    permute(s.toCharArray(), 0, result);
    return result;
  }

  private void permute(char[] arr, int index, List<String> result) {
    if (index == arr.length) {
      result.add(new String(arr));
      return;
    }
    for (int i = index; i < arr.length; i++) {
      swap(arr, index, i);
      permute(arr, index + 1, result);
      swap(arr, index, i);
    }
  }

  private void swap(char[] arr, int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}