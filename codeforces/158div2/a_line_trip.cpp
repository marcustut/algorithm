#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // brute force
        int ans = 0;
        while (true)
        {
            int fuel = ans;
            int travelled = 0;
            int station = 0;
            for (int j = 0; j < x; j++)
            {
                if (fuel <= 0)
                    break;

                travelled++;
                fuel--;

                // refuel
                if (station < n && j + 1 == a[station])
                {
                    fuel = ans;
                    station++;
                }
            }
            station = n - 1;
            for (int j = x; j > 0; j--)
            {
                if (fuel <= 0)
                    break;

                travelled++;
                fuel--;

                // refuel
                if (station >= 0 && j - 1 == a[station])
                {
                    fuel = ans;
                    station--;
                }
            }

            if (travelled == x * 2)
                break;

            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}