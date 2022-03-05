#include <bits/stc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid)
{
  int count = 0;

  for (int row = 0; row < grid.size(); row++)
    for (int col = 0; col < grid[row].size(); col++)
      if (grid[row][col] == '1') {
        sink(grid, row, col);
        count++;
      }

  return count;
}

void sink(vector<vector<char>>& grid, int row, int col)
{
  if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()) {
    grid[row][col] = 0;
    sink(grid, row-1, col);
    sink(grid, row+1, col);
    sink(grid, row, col-1);
    sink(grid, row, col+1);
  }
}

int main()
{
}
