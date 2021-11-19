#include <bits/stdc++.h>

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    // get the sum of all ranges
    int total = (b - a) + (d - c);
    int intersection = std::max(std::min(d, b) - std::max(c, a), 0);

    std::cout << total - intersection << "\n";
}