#include <bits/stdc++.h>
#include <utils/display.h>
using namespace std;

vector<int> solve(int n, int k) {
    int length = n - k + 1;
    int num_of_array = n - length + 1;

    cout << "length: " << length << endl;
    cout << "num_of_array: " << num_of_array << endl;

    int min = INT_MIN;

    for (int i = 0; i < num_of_array; i++) {
        vector<int> c;

        for (int j = 0; j < length; j++)
            c.push_back((j + i) % n + 1);

        printVec(c);

        int cost = *max_element(c.begin(), c.end()) + *min_element(c.begin(), c.end());

        cout << "cost " << i + 1 << ": " << cost << endl;
    }

    return {};
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> ans = solve(n, k);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}


// 3
// 5 3
// 5 1
// 6 6

