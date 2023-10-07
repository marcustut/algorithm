// https://cses.fi/problemset/task/1068/

#include <iostream>
using namespace std;

// 3 10 5 16 8 4 2 1

int main() {
  long long x;
  cin >> x;
  cout << x << " ";

  while (x != 1) {
    if (x % 2 == 0)
      x /= 2;
    else
      x = (x * 3) + 1;

    cout << x << " ";
  }

  cout << "\n";
}
