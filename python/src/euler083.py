# Problem 83: Path Sum: Four Ways
# In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down, is indicated in bold red and is equal to 2297.
# Find the minimal path sum from the top left to the bottom right by moving left, right, up, and down in matrix.txt, a 31K text file containing an 80 by 80 matrix.
# Answer: 425185
# Execution time: ~200ms on modern hardware
# Optimizations: Dijkstra's algorithm for grid shortest path
# Interesting notes: AI-generated solution using priority queue for 4-directional movement

import heapq

def solve():
    with open('../cpp/src/p081_matrix.txt') as f:
        matrix = [list(map(int, line.split(','))) for line in f]
    n = len(matrix)
    dist = [[float('inf')] * n for _ in range(n)]
    dist[0][0] = matrix[0][0]
    pq = [(matrix[0][0], 0, 0)]
    while pq:
        cost, i, j = heapq.heappop(pq)
        if cost > dist[i][j]:
            continue
        for di, dj in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            ni, nj = i + di, j + dj
            if 0 <= ni < n and 0 <= nj < n:
                new_cost = cost + matrix[ni][nj]
                if new_cost < dist[ni][nj]:
                    dist[ni][nj] = new_cost
                    heapq.heappush(pq, (new_cost, ni, nj))
    return dist[n-1][n-1]