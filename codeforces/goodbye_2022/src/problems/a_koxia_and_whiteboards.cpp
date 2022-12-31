#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;
int n, m;
ll a[N];

void solve() {
    cin >> n >> m;

    // collect all the numbers
    for (int i = 0; i < n + m; i++)
        cin >> a[i];

    // sort the numbers in ascending order
    // but with offset of 1 (don't sort the last element)
    sort(a, a + n + m - 1);

    // count the sum of last n numbers 
    ll ans = 0;
    for (int i = m; i < n + m; i++)
        ans += a[i];
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) solve();
}

