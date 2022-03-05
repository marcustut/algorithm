// orignal solution in python
// https://github.com/limyunkai19/games/blob/master/chocolate-bar-game/react-code/ai/ai.py

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool canWin(int row, int col) {
  // dp
  // calculated before
  if (dp[row][col] != -1)
    return dp[row][col];

  // base case
  if (row == 1 && col == 1)
    return dp[row][col] = false;

  // recursive case
  // try all horizontal cut
  for (int r = 1; r < row; r++) {
    rLeft = max(r, row - r);

    if (!canWin(rLeft, col)) {
      // found a move that leads to losing state
      // cache the optimal move together too, which is r
      return dp[row][col] = true; // cache the result and return
    }
  }
  // try all vertical cut
  for (int c = 1; c < col; c++) {
    cLeft = max(c, col - c);

    // found a move that leads to losing state
    if (!canWin(cLeft, row))
      return dp[row][col] = true; // cache the result and return
  }

  // we've tried all possible moves, and all lead to winning state
  return dp[row][col] = false; // cache the result and return
}

int main() {
  int row, col;
  cin >> row >> col;

  dp.assign(vector<int>(-1, col), row);
  cout << canWin(row, col) << '\n';
}
