# Problem 96: Su Doku
# The file contains 50 Su Doku puzzles, find the sum of the 3-digit numbers in the top left corner of each solution grid.
# Answer: 24702
# Execution time: ~1000ms on modern hardware
# Optimizations: Backtracking solver for sudoku
# Interesting notes: AI-generated solution using backtracking for sudoku

def solve_sudoku(grid):
    def is_valid(row, col, num):
        for i in range(9):
            if grid[row][i] == num or grid[i][col] == num:
                return False
        start_row = (row // 3) * 3
        start_col = (col // 3) * 3
        for i in range(3):
            for j in range(3):
                if grid[start_row + i][start_col + j] == num:
                    return False
        return True
    def backtrack():
        for row in range(9):
            for col in range(9):
                if grid[row][col] == 0:
                    for num in range(1, 10):
                        if is_valid(row, col, num):
                            grid[row][col] = num
                            if backtrack():
                                return True
                            grid[row][col] = 0
                    return False
        return True
    backtrack()
    return int(''.join(map(str, grid[0][:3])))

def solve():
    total = 0
    with open('../cpp/src/p096_sudoku.txt') as f:
        lines = f.readlines()
    i = 0
    while i < len(lines):
        if lines[i].startswith('Grid'):
            grid = []
            for j in range(9):
                grid.append([int(x) for x in lines[i+1+j].strip()])
            total += solve_sudoku(grid)
            i += 10
        else:
            i += 1
    return total

if __name__ == "__main__":
    print(solve())