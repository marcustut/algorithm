// https://atcoder.jp/contests/abc284/tasks/abc284_a
// https://atcoder.jp/contests/abc284/submissions/37865390
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = n - 1; i >= 0; i--)
        cout << v[i] << endl;
}
