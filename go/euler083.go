// https://projecteuler.net/problem=83

// Path Sum: Four Ways

// In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down, is indicated in bold red and is equal to 2297.

// Find the minimal path sum from the top left to the bottom right by moving left, right, up, and down in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing an 80 by 80 matrix.

// Answer: 425185

// Execution time: ~10ms

// Optimizations: Dijkstra's algorithm with priority queue

// Interesting notes: AI-generated solution using heap-based Dijkstra

package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Item struct {
	value    int
	priority int
	index    int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool { return pq[i].priority < pq[j].priority }

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil
	item.index = -1
	*pq = old[0 : n-1]
	return item
}

func pathSumFourWays() int {
	matrix := readMatrix()
	size := len(matrix)
	dx := []int{-1, 1, 0, 0}
	dy := []int{0, 0, -1, 1}
	dist := make([][]int, size)
	for i := range dist {
		dist[i] = make([]int, size)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
		}
	}
	dist[0][0] = matrix[0][0]
	pq := &PriorityQueue{}
	heap.Init(pq)
	heap.Push(pq, &Item{value: 0*size + 0, priority: matrix[0][0]})
	for pq.Len() > 0 {
		item := heap.Pop(pq).(*Item)
		x := item.value / size
		y := item.value % size
		if x == size-1 && y == size-1 {
			return dist[x][y]
		}
		for d := 0; d < 4; d++ {
			nx := x + dx[d]
			ny := y + dy[d]
			if nx >= 0 && nx < size && ny >= 0 && ny < size {
				if dist[nx][ny] > dist[x][y]+matrix[nx][ny] {
					dist[nx][ny] = dist[x][y] + matrix[nx][ny]
					heap.Push(pq, &Item{value: nx*size + ny, priority: dist[nx][ny]})
				}
			}
		}
	}
	return -1
}

func readMatrix() [][]int {
	file, err := os.Open("matrix.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	matrix := [][]int{}
	for scanner.Scan() {
		line := scanner.Text()
		parts := strings.Split(line, ",")
		row := []int{}
		for _, p := range parts {
			num, _ := strconv.Atoi(strings.TrimSpace(p))
			row = append(row, num)
		}
		matrix = append(matrix, row)
	}
	return matrix
}

func main() {
	fmt.Println(pathSumFourWays())
}