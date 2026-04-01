/*
Passcode Derivation

A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.

The final answer to the problem is 73162890.

Execution time measurements: Less than 1 ms on standard hardware.

Details on any optimizations made during development: Topological sort using Kahn's algorithm for passcode reconstruction.

Interesting notes or insights from the AI implementation process: AI-generated solution using graph theory for ordering digits from partial sequences.
*/
package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.*;
import java.util.*;

public class Solution079 implements Solution {
  public String solve() {
    List<String> logs = new ArrayList<>();
    try (InputStream is = getClass().getResourceAsStream("/keylog.txt");
         BufferedReader br = new BufferedReader(new InputStreamReader(is))) {
      String line;
      while ((line = br.readLine()) != null) {
        if (line.length() == 3) logs.add(line);
      }
    } catch (IOException e) {
      return "";
    }
    List<Set<Integer>> graph = new ArrayList<>();
    for (int i = 0; i < 10; ++i) graph.add(new HashSet<>());
    int[] indegree = new int[10];
    Set<Integer> digits = new HashSet<>();
    for (String log : logs) {
      int a = log.charAt(0) - '0', b = log.charAt(1) - '0', c = log.charAt(2) - '0';
      digits.add(a);
      digits.add(b);
      digits.add(c);
      if (!graph.get(a).contains(b)) {
        graph.get(a).add(b);
        ++indegree[b];
      }
      if (!graph.get(b).contains(c)) {
        graph.get(b).add(c);
        ++indegree[c];
      }
    }
    Queue<Integer> q = new LinkedList<>();
    for (int d : digits) {
      if (indegree[d] == 0) q.add(d);
    }
    StringBuilder passcode = new StringBuilder();
    while (!q.isEmpty()) {
      int d = q.poll();
      passcode.append(d);
      for (int next : graph.get(d)) {
        --indegree[next];
        if (indegree[next] == 0) q.add(next);
      }
    }
    return passcode.toString();
  }
}