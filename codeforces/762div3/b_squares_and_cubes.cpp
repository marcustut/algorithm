#include <bits/stdc++.h>
using namespace std;

// count squares and cubes from 1..n
// O(n√n) - too slow (unable to complete within 1s)
int square_and_cube(int n) {
  int count = 0;

  for (double i = 1; i <= n; i++) {
    double square = sqrt(i);
    double cube = cbrt(i);
    if (square == (int)square || cube == (int)cube)
      count++;
  }

  return count;
}

int square_and_cube_fast(int n) {
  int count = 0;

  int cube_upper_bound = cbrt(n);

  for (int i = 1; i <= cube_upper_bound; i++)
    if ((i * i <= cube_upper_bound) ||  (i * i * i <= cube_upper_bound))
      count++;

  // num of squares + num of cubes - num of both
  return (floor(sqrt(n)) + floor(cbrt(n))) - count;
}

int square_and_cube_faster(int n) {
  return floor(sqrt(n + 0.5L)) + floor(cbrt(n + 0.5L)) - floor(pow(n + 0.5L, 1.0L / 6));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << square_and_cube_faster(n) << '\n';
  }
  return 0;
}
