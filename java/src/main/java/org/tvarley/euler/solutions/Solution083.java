// https://projecteuler.net/problem=83
// Path Sum: Four Ways
//
// NOTE: This problem is a significantly more challenging version of Problem 81.
//
// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down, is indicated in bold red and is equal to 2297.
//
// $$ \begin{pmatrix} \color{red}{131} & 673 & \color{red}{234} & \color{red}{103} & \color{red}{18}\\ \color{red}{201} & \color{red}{96} & \color{red}{342} & 965 & \color{red}{150}\\ 630 & 803 & 746 & \color{red}{422} & \color{red}{111}\\ 537 & 699 & 497 & \color{red}{121} & 956\\ 805 & 732 & 524 & \color{red}{37} & \color{red}{331} \end{pmatrix} $$
//
// Find the minimal path sum from the top left to the bottom right by moving left, right, up, and down in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.
//
// Answer: 425185
//
// Completed on: 2024-12-04
// Time: ~50ms
// Optimizations: Dijkstra's algorithm with priority queue
// Notes: All four directions allowed. Used 2D dist array and priority queue to find minimal path.

package org.tvarley.euler.solutions;

import org.tvarley.euler.Solution;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Solution083 implements Solution {
    private static class Node implements Comparable<Node> {
        int cost, i, j;

        Node(int cost, int i, int j) {
            this.cost = cost;
            this.i = i;
            this.j = j;
        }

        public int compareTo(Node other) {
            return Integer.compare(this.cost, other.cost);
        }
    }

    public String solve() {
        int[][] matrix = readMatrix();
        int n = 80;
        int[][] dist = new int[n][n];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = matrix[0][0];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(matrix[0][0], 0, 0));
        int[] di = {-1, 0, 1, 0};
        int[] dj = {0, 1, 0, -1};
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int cost = node.cost, i = node.i, j = node.j;
            if (cost > dist[i][j]) continue;
            for (int d = 0; d < 4; ++d) {
                int ni = i + di[d], nj = j + dj[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    int ncost = cost + matrix[ni][nj];
                    if (ncost < dist[ni][nj]) {
                        dist[ni][nj] = ncost;
                        pq.add(new Node(ncost, ni, nj));
                    }
                }
            }
        }
        return Integer.toString(dist[n - 1][n - 1]);
    }

    private int[][] readMatrix() {
        int[][] matrix = new int[80][80];
        try (BufferedReader br = new BufferedReader(new InputStreamReader(
                getClass().getResourceAsStream("/matrix.txt")))) {
            String line;
            int row = 0;
            while ((line = br.readLine()) != null && row < 80) {
                String[] tokens = line.split(",");
                for (int col = 0; col < 80 && col < tokens.length; ++col) {
                    matrix[row][col] = Integer.parseInt(tokens[col]);
                }
                ++row;
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return matrix;
    }
}