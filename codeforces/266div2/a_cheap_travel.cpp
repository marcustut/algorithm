#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int a, int b) {
    return min({
        n * a, 
        ((n - (n % m)) / m) * b + b,
        ((n - (n % m)) / m) * b + (n - (n - (n % m))) * a
    });

    return min(
        n * a, 
        n / m * b + min(n % m * a, b)
    );
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    // print("n={}, m={}, a={}, b={}\n", n, m, a, b);

    cout << solve(n,m,a,b) << '\n';

    return 0;
}
