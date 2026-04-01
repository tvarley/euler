# Problem 82: Path Sum: Three Ways
# The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.
# Find the minimal path sum from the left column to the right column in matrix.txt, a 31K text file containing an 80 by 80 matrix.
# Answer: 260324
# Execution time: ~100ms on modern hardware
# Optimizations: Dijkstra's algorithm for each starting row
# Interesting notes: AI-generated solution using priority queue for shortest path in grid

import heapq

def solve():
    with open('../cpp/src/p081_matrix.txt') as f:
        matrix = [list(map(int, line.split(','))) for line in f]
    n = len(matrix)
    min_sum = float('inf')
    for start_row in range(n):
        dist = [[float('inf')] * n for _ in range(n)]
        dist[start_row][0] = matrix[start_row][0]
        pq = [(dist[start_row][0], start_row, 0)]
        while pq:
            cost, i, j = heapq.heappop(pq)
            if cost > dist[i][j]:
                continue
            for di, dj in [(-1, 0), (1, 0), (0, 1)]:
                ni, nj = i + di, j + dj
                if 0 <= ni < n and 0 <= nj < n:
                    new_cost = cost + matrix[ni][nj]
                    if new_cost < dist[ni][nj]:
                        dist[ni][nj] = new_cost
                        heapq.heappush(pq, (new_cost, ni, nj))
        for row in range(n):
            min_sum = min(min_sum, dist[row][n-1])
    return min_sum