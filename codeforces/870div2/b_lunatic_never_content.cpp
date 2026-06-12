#include <print>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a) {
    int n = a.size();

    // int x = 0;
    // for (size_t i = 0; i < a.size() / 2; i++)
    //     x = gcd(x, abs(a[i] - a[n - 1 - i]));
    // return x;

    return ranges::fold_left(
        views::iota(0, n/2) | views::transform([&](int i){ return abs(a[i] - a[n-1-i]); }), 
        0, 
        [](auto x, auto y){ return gcd(x, y); }
    );
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        while (n--) {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        cout << solve(arr) << "\n";
    }
    return 0;
}
