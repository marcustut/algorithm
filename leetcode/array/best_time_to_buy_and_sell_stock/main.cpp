#include <bits/stdc++.h>
#include "utils/display.h"
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProfit(vector<int>& prices)
{
    if (prices.size() == 1) return 0;
    if (prices.size() == 2) return max(prices[1] - prices[0], 0);

    int buy(0), sell(1), profit(0);

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < prices[buy]) buy = i;
      if (prices[i] >= prices[sell]) sell = i;
      if (sell < buy && i != prices.size() - 1) sell = buy + 1;
      int local_profit = prices[sell] - prices[buy];
      if (local_profit > profit && sell > buy) profit = local_profit;
    }

    return profit;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
int maxProfitBruteForce(vector<int>& prices)
{
    int max(0);

    for (int i = 0; i < prices.size(); i++)
        for (int j = i + 1; j < prices.size(); j++)
            if (prices[j] - prices[i] > max)
                max = prices[j] - prices[i];

    return max;
}

int main()
{
    vector<tuple<vector<int>, int>> tcs = {
        make_tuple(vector<int>{7,1,5,3,6,4}, 5),
        make_tuple(vector<int>{7,6,4,3,1}, 0),
        make_tuple(vector<int>{2,1,2,1,0,1,2}, 2),
        make_tuple(vector<int>{3,3,5,0,0,3,1,4}, 4),
    };

    for (auto &tc : tcs) {
        int profit = maxProfit(get<0>(tc));
        // int profit = maxProfitBruteForce(get<0>(tc));
        assert(profit == get<1>(tc));
    }

    return 0;
}
