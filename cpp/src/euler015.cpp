// https://projecteuler.net/problem=15
// Lattice paths

// Starting in the top left corner of a 2×2 grid,
// and only being able to move to the right and down,
// there are exactly 6 routes to the bottom right corner.
//
// How many such routes are there through a 20×20 grid?

// Answer: 137846528820

#include <iostream>
#include <vector>
#include <cstdint>

uint64_t lattice_path(size_t grid_size)
{
  std::vector< uint64_t > grid((grid_size+1)*(grid_size+1),1);

  for (int x = grid_size-1; 0 <= x ; x--) {
    for (int y = grid_size-1; 0 <= y; y--) {
      int pos = (y*(grid_size+1))+x;
      grid.at(pos) = grid.at(pos+1) + grid.at(pos+(grid_size+1));
    }
  }
  return grid.at(0);
}

#if ! defined UNITTEST_MODE
int main(int argc, char const *argv[])
{
  std::cout << "Answer: " << lattice_path(2) << std::endl;
  std::cout << "Answer: " << lattice_path(20) << std::endl;
  return 0;
}
#endif // #if ! defined UNITTEST_MODE
