#include <bits/stdc++.h>
using namespace std;

bool compare_vector(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
        return false;

    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];

        int ans, i = 0;
        vector<int> board(n, 0);
        while (true)
        {
            if (compare_vector(c, board))
                break;

            int idx = i % n;

            // init
            if (board[idx] == 0)
                board[idx] = 1;
            // move
            if (board[idx] != 0)
            {
                board[min(idx + 1, n - 1)]++;
            }
            // teleport

            i++;
        }

        cout << ans << endl;
    }

    return 0;
}