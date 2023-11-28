#include <bits/stdc++.h>
#include <ranges>
using namespace std;

void dp(const std::vector<int> &states, std::vector<int> &data,
        std::vector<int> &combinations, int n, int m, int i, int j) {
  // Runs out of moves, return
  if (i == m) {
    // Construct a combination
    std::vector<int> tmp;
    for (int k = 0; k < m; k++)
      tmp.push_back(data[k]);

    //
    combinations.push_back(accumulate(tmp.begin(), tmp.end(), 0,
                                      [](int acc, int x) { return acc ^ x; }));
    return;
  }

  if (j >= n)
    return;

  data[i] = states[j];
  dp(states, data, combinations, n, m, i + 1, j + 1);

  dp(states, data, combinations, n, m, i, j + 1);
}

int binary_to_decimal(const std::vector<int> &bits) {
  int count = 0;
  for (int i = bits.size() - 1; i >= 0; i--)
    count += bits[i] * pow(2, bits.size() - 1 - i);
  return count;
}

int main() {
  int n, m, v;
  cin >> n >> m >> v;

  std::vector<int> lights;
  for (int i = 0; i < v; i++)
    lights.push_back(1);
  for (int i = 0; i < n - v; i++)
    lights.push_back(0);

  int num = binary_to_decimal(lights);

  std::vector<int> states;
  std::vector<int> data;
  for (int i = 0; i < pow(2, n); i++) {
    states.push_back(i);
    data.push_back(i);
  }

  std::vector<int> combinations;

  dp(states, data, combinations, pow(2, n), m, 0, 0);

  int count = 0;
  for (auto x : combinations | std::ranges::views::filter(
                                   [num](int x) { return x == num; })) {
    count++;
  }

  cout << count % 10567201 << '\n';

  return 0;
}
