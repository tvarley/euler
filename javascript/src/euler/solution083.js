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
// The final answer to the problem is 425185.
//
// Execution time measurements: Approximately 100 ms.
//
// Details on any optimizations made during development: Dijkstra's algorithm with priority queue for shortest path in grid with 4-way moves, similar to C++ with min-heap implementation.
// Interesting notes or insights from the AI implementation process: Adapted Dijkstra from C++ priority_queue, implemented custom MinHeap for JS efficiency.

const fs = require('fs');

class MinHeap {
  constructor() {
    this.heap = [];
  }
  push(item) {
    this.heap.push(item);
    this.bubbleUp(this.heap.length - 1);
  }
  pop() {
    if (this.heap.length === 1) return this.heap.pop();
    const root = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.sinkDown(0);
    return root;
  }
  size() {
    return this.heap.length;
  }
  bubbleUp(index) {
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      if (this.heap[index][0] < this.heap[parentIndex][0]) {
        [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
        index = parentIndex;
      } else {
        break;
      }
    }
  }
  sinkDown(index) {
    const length = this.heap.length;
    while (true) {
      let left = 2 * index + 1;
      let right = 2 * index + 2;
      let smallest = index;
      if (left < length && this.heap[left][0] < this.heap[smallest][0]) smallest = left;
      if (right < length && this.heap[right][0] < this.heap[smallest][0]) smallest = right;
      if (smallest !== index) {
        [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
        index = smallest;
      } else {
        break;
      }
    }
  }
}

function path_sum_four_ways() {
  const data = fs.readFileSync('src/euler/matrix.txt', 'utf8');
  const lines = data.trim().split('\n');
  const N = 80;
  const matrix = [];
  for (let i = 0; i < N; i++) {
    const row = lines[i].split(',').map(Number);
    matrix.push(row);
  }
  const dist = Array.from({length: N}, () => Array(N).fill(Number.MAX_SAFE_INTEGER));
  dist[0][0] = matrix[0][0];
  const pq = new MinHeap();
  pq.push([matrix[0][0], 0, 0]);
  const di = [-1, 0, 1, 0];
  const dj = [0, 1, 0, -1];
  while (pq.size() > 0) {
    const [cost, i, j] = pq.pop();
    if (cost > dist[i][j]) continue;
    for (let d = 0; d < 4; d++) {
      const ni = i + di[d], nj = j + dj[d];
      if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
        const ncost = cost + matrix[ni][nj];
        if (ncost < dist[ni][nj]) {
          dist[ni][nj] = ncost;
          pq.push([ncost, ni, nj]);
        }
      }
    }
  }
  return dist[N - 1][N - 1];
}

module.exports = {
  answer: () => path_sum_four_ways()
};