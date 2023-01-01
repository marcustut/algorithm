#include <bits/stdc++.h>
using namespace std;

const int NUM_BUCKETS = 3;
const int NUM_POURS = 100;

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    // first of tuple is capacitiy, second is amount
    vector<vector<int>> milk;

    // collect input
    for (int i = 0; i < NUM_BUCKETS; i++) {
        int capacity, amount;
        cin >> capacity >> amount;

        milk.push_back({capacity, amount});
    }

    for (int i = 0; i < NUM_POURS; i++) {
        const int curr_i = i % NUM_BUCKETS;
        const int next_i = (i + 1) % NUM_BUCKETS;

        const int capacity = milk[next_i][0];
        int amount = min(milk[curr_i][1], capacity - milk[next_i][1]);
        milk[curr_i][1] -= amount;
        milk[next_i][1] += amount;
    }

    for (int i = 0; i < NUM_BUCKETS; i++) cout << milk[i][1] << endl;
}
