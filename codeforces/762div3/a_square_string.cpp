#include <bits/stdc++.h>
using namespace std;

bool is_square(string s) {
  // if not even
  if (s.size() % 2 != 0) return false;

  vector<char> arr;

  for (int i = 0; i < s.size() / 2; i++)
    arr.push_back(s[i]);

  for (int i = s.size() / 2; i < s.size(); i++)
    if (arr[i - (s.size() / 2)] != s[i])
      return false;

  return true;
}

bool is_square_fast(string s) {
  int n = s.size();
  // return s.compare(0, n / 2, s, n / 2) == 0;
  return n % 2 == 0 && (s.substr(0, n / 2) == s.substr(n / 2));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (is_square_fast(s)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
