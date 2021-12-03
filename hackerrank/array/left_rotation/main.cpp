#include <bits/stdc++.h>

std::vector<int> rotLeft(std::vector<int> a, int d) {
    if (a.size() < 2) return a;
    
    // O(d)
    for (int i = 0; i < d; i++)
    {
        a.push_back(a[0]);
        a.erase(a.begin());
    }
    
    return a;
}
