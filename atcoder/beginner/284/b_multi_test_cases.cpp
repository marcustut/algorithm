// https://atcoder.jp/contests/abc284/tasks/abc284_b
// atcoder.jp/contests/abc284/submissions/37886727
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int count = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2 != 0) count++;
        }

        cout << count << endl;
    }
}
