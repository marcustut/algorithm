// https://cses.fi/problemset/task/1094
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;

  vector<ll> nums;
  ll moves = 0;
  ll biggest = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums.push_back(x);
  }

  if (n == 1) {
    cout << 0;
    return 0;
  }

  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i - 1] > biggest)
      biggest = nums[i - 1];

    if (nums[i] < biggest)
      moves += biggest - nums[i];
  }

  cout << moves << '\n';
}
