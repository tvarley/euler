#!/usr/bin/env ruby
# Lattice paths

# https://projecteuler.net/problem=15
# Starting in the top left corner of a 2x2 grid, and only being able to move to
# the right and down, there are exactly 6 routes to the bottom right corner.
# How many such routes are there through a 20x20 grid?

# Answer: 137846528820

def lattice_paths(grid_size)
  grid_dimension = grid_size + 1
  grid = Array.new(grid_dimension * grid_dimension) { 1 }
  (grid_size - 1).downto(0) do |x|
    (grid_size - 1).downto(0) do |y|
      pos = (y * grid_dimension) + x
      grid[pos] = grid[pos + 1] + grid[pos + grid_dimension]
    end
  end
  grid[0]
end

puts lattice_paths(20) if __FILE__ == $PROGRAM_NAME
