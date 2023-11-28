#include <bits/stdc++.h>
using namespace std;

// x x x x
// x x x x
// x x x x
// n = 3, m = 4

vector<long long> solution(int n, int m, vector<vector<int>> q)
{
    vector<long long> res;
    vector<bool> deactivated_rows(n + 1);
    vector<bool> deactivated_cols(m + 1);

    for (size_t k = 0; k < q.size(); k++)
    {
        const int type = q[k][0];
        switch (type)
        {
        case 0:
        {
            long long val = LLONG_MAX;

            for (long long i = 1; i <= n; i++)
            {
                if (deactivated_rows[i])
                    continue;

                for (long long j = 1; j <= m; j++)
                {
                    if (deactivated_cols[j])
                        continue;

                    if (i * j < val)
                        val = i * j;
                }
            }

            res.push_back(val);
            break;
        }
        case 1:
        {
            const int row = q[k][1];
            deactivated_rows[row] = true;
            break;
        }
        case 2:
        {
            const int col = q[k][1];
            deactivated_cols[col] = true;
            break;
        }
        default:
            throw runtime_error("Unsupported query type");
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> queries = {{0}, {1, 2}, {0}, {2, 1}, {0}, {1, 1}, {0}};
    auto res = solution(3, 4, queries);
    for (auto x : res)
        cout << x << ' ';
    cout << '\n';
}