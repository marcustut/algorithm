// https://cses.fi/problemset/task/1071
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int t;
  cin >> t;

  while (t--) {
    ll y, x;
    cin >> y >> x;

    ll z = max(y, x);
    ll zz = (z - 1) * (z - 1);
    ll ans;

    // if z is odd
    if (z % 2 != 0) {
      if (y == z)
        ans = zz + x;
      else
        ans = zz + 2 * z - y;
    } else {
      if (x == z)
        ans = zz + y;
      else
        ans = zz + 2 * z - x;
    }

    cout << ans << "\n";
  }
}
