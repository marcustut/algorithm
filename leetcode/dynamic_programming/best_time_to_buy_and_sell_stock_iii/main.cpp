#include <bits/stdc++.h>
#include "utils/display.h"
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProfitFastest(vector<int>& prices) {
  int buy1 = INT_MAX;
  int buy2 = INT_MAX;
  int profit1 = 0;
  int profit2 = 0;
  for (auto& price : prices) {
    buy1 = min(buy1, price);               // best observed buy price seen
    profit1 = max(profit1, price - buy1);  // best observed profit window
    buy2 = min(buy2, price - profit1);     // best buy price post-profit1
    profit2 = max(profit2, price - buy2);  // best combined two transaction profit
  }
  return profit2;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int maxProfitDivideAndConquer(vector<int>& prices) {
  if (prices.size() < 2) return 0;

  int left_min = prices[0];
  vector<int> left = vector<int>(prices.size(), 0);
  for (int i = 1; i < prices.size(); i++) {
    left[i] = max(left[i - 1], prices[i] - left_min);
    left_min = min(left_min, prices[i]);
  }

  int right_max = prices[prices.size() - 1];
  vector<int> right = vector<int>(prices.size(), 0);
  for (int i = prices.size() - 2; i >= 0; i--) {
    right[i] = max(right[i + 1], right_max - prices[i]);
    right_max = max(right_max, prices[i]);
  }

  int profit = right[0];
  for (int i = 1; i < prices.size(); i++)
    profit = max(profit, left[i - 1] + right[i]);

  return profit;
}

// Time Complexity: O(2^n) / O(n)
// Space Complexity: O(n)
int maxProfitDp(vector<int>& prices) {
  vector<vector<int>> memo(prices.size(), vector<int>(5, -1));

  std::function<int(int, int)> dp = [&prices, &memo, &dp](
                                        int day, int transaction_left) {
    // Base case
    if (day >= prices.size() || transaction_left <= 0) return 0;

    // Optimisation: Return cached result
    if (memo[day][transaction_left] != -1) return memo[day][transaction_left];

    // (Buy, Sell, Buy, Sell) <- must be in this sequence, hence if buy then always even number
    bool should_buy = transaction_left % 2 == 0;

    // If bought (loss), if sold (profit).
    int pnl = should_buy ? -prices[day] : prices[day];

    // Move on to the next day
    int profit = max(dp(day + 1, transaction_left),           // Scenario 1: No buy / sell action
                     dp(day + 1, transaction_left - 1) + pnl  // Scenario 2: Made a transaction (PnL accounts for buy / sell)
    );

    // Cache the result
    memo[day][transaction_left] = profit;

    return profit;
  };

  return dp(0, 4);
}

int main() {
  vector<tuple<vector<int>, int>> tcs = {
      make_tuple(vector<int>{3, 3, 5, 0, 0, 3, 1, 4}, 6),
      make_tuple(vector<int>{7, 6, 4, 3, 1}, 0),
      make_tuple(vector<int>{1, 2, 3, 4, 5}, 4),
  };

  for (auto& tc : tcs) {
    auto start = std::chrono::high_resolution_clock::now();
    int profit = maxProfitDp(get<0>(tc));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    if (profit != get<1>(tc)) {
      cerr << "[FAILED]: " << profit << " != " << get<1>(tc) << endl;
      return -1;
    }
    cout << "[PASSED] " << duration.count() << "microseconds Output: " << get<1>(tc) << ", Input: ";
    printVec(get<0>(tc));
  }

  return 0;
}
