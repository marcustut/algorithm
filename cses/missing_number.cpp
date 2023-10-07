// https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
using namespace std;

#define ll long long;

int main() {
  int n;
  cin >> n;
  vector<int> nums;

  for (int i = 0; i < n - 1; i++) {
    int num;
    cin >> num;
    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());

  if (nums.size() == 1) {
    if (nums[0] == 2)
      cout << 1 << '\n';
    else if (nums[0] == 1)
      cout << 2 << '\n';
    return 0;
  }

  for (int i = 0; i < nums.size() - 1; i++)
    if (nums[i] + 1 != nums[i + 1]) {
      cout << nums[i] + 1 << '\n';
      return 0;
    }

  cout << n << '\n';
}
