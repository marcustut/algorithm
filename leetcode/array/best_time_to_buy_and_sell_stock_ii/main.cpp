#include <bits/stdc++.h>
#include "utils/display.h"
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProfit(vector<int>& prices) {
  int profit = 0;
  for (size_t i = 1; i < prices.size(); i++)
    if (prices[i] > prices[i - 1])
      profit += prices[i] - prices[i - 1];
  return profit;
}

class MaxProfitAccumulator {
 public:
  MaxProfitAccumulator(int profit, int last_price) : profit(profit), last_price(last_price) {}
  friend MaxProfitAccumulator operator+(MaxProfitAccumulator acc, int price) {
    if (price > acc.last_price) acc.profit += price - acc.last_price;
    acc.last_price = price;
    return acc;
  }

  int get_profit() const { return this->profit; }

 private:
  int profit;
  int last_price;
};

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProfitReduce(vector<int>& prices) {
  return std::accumulate(prices.begin() + 1, prices.end(), MaxProfitAccumulator(0, prices[0])).get_profit();
}

int main() {
  vector<tuple<vector<int>, int>> tcs = {
      make_tuple(vector<int>{6, 1, 3, 2, 4, 7}, 7),
      make_tuple(vector<int>{7, 1, 5, 3, 6, 4}, 7),
      make_tuple(vector<int>{7, 6, 4, 3, 1}, 0),
      make_tuple(vector<int>{1, 2, 3, 4, 5}, 4),
  };

  for (auto& tc : tcs) {
    auto start = std::chrono::high_resolution_clock::now();
    int profit = maxProfitReduce(get<0>(tc));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    if (profit != get<1>(tc)) {
      cerr << "[FAILED]: " << profit << " != " << get<1>(tc) << endl;
      return -1;
    }
    cout << "[PASSED] " << duration.count() << "nanoseconds Output: " << get<1>(tc) << ", Input: ";
    printVec(get<0>(tc));
  }

  return 0;
}
