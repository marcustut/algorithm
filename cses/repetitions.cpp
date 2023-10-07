// https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  string s;
  cin >> s;
  int max = 0;
  int count = 1;

  if (s.size() == 1) {
    cout << "1\n";
    return 0;
  }

  for (size_t i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1])
      count++;
    else
      count = 1;

    if (count > max)
      max = count;
  }

  cout << max << '\n';
}
