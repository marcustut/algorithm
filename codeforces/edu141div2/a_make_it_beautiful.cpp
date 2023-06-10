#include <bits/stdc++.h>
using namespace std;

bool check_ugly(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == sum) return true;
        sum += a[i];
    }
    return false;
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a[n];
        int sum = 0;
        bool ugly = false;
        for (int i = 0; i < n; i++) { 
            cin >> a[i];

            if (a[i] == sum) ugly = true;

            sum += a[i];
        };

        if (!ugly) {
            cout << "YES" << endl;
            print_array(a, n);
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(a[i], a[j]);
                    if (!check_ugly(a, n)) {
                        cout << "YES" << endl;
                        print_array(a, n);
                        goto end;
                        swap(a[i], a[j]);
                    }
                }
            }

            cout << "NO" << endl;
        }

        end:;
    }
}
