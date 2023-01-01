#include <bits/stdc++.h>
using namespace std;

const int NUM_SHELLS = 3;

int main()
{
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    // construct the shells
    vector<int> shells(NUM_SHELLS);
    for (int i = 0; i < NUM_SHELLS; i++) shells[i] = i;

    vector<int> counter(NUM_SHELLS);
    for (int i = 0; i < n; i++)  {
        int a, b, g;
        cin >> a >> b >> g;

        // offset by 1 due to zero indexing
        a--; b--; g--;

        // swap the shells
        swap(shells[a], shells[b]);

        // increment the counter if the guesses are correct
        counter[shells[g]]++;
    }

    cout << max({counter[0], counter[1], counter[2]}) << endl;
}
