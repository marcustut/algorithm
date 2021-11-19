#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
int hammingDistance(int x, int y)
{
    // Convert to binary form
    bitset<32> xb(x), yb(y);
    int ans(0);

    // iterate through each bit
    for (int i = 0; i < 32; i++)
        // if both are not equal then increase the distance
        if (xb[i] != yb[i])
            ans++;

    return ans;
}

int main()
{
    cout << hammingDistance(3, 1) << '\n';
}