#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://www.youtube.com/watch?v=UqS1iYch0aI
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        int ans = 0, table = 0, ambi = 0;

        for (int i = 0; i < n; i++) {
            if (u[i] == 'I') {
                if (table < x) table++, ans++; 
            }
            else if (u[i] == 'A') {
                if (ans < table * s) ans++, ambi++;
                else if (table < x) table++, ans++;
            }
            else {
                if (ans < table * s) ans++;
                else if (ambi > 0 && table < x) table++, ans++, ambi--; // turning 'A' into 'I'
            }
        }

        cout << ans << "\n";
    }
}
