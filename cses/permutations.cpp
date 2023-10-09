#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "1\n";
    return 0;
  }

  if (n == 2 || n == 3) {
    cout << "NO SOLUTION";
    return 0;
  }

  // 2 4 1 3
  // 4 2 5 1 3

  if (n % 2 == 0) {
    for (int i = 1; i <= n; i++)
      if (i % 2 == 0)
        cout << i << " ";
    for (int i = 1; i <= n; i++)
      if (i % 2 != 0)
        cout << i << " ";
  } else {
    for (int i = n; i > 0; i--)
      if (i % 2 == 0)
        cout << i << " ";
    for (int i = n; i > 0; i--)
      if (i % 2 != 0)
        cout << i << " ";
  }

  return 0;
}
