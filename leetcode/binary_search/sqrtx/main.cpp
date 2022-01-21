#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mySqrt(int x) {
  unsigned int start = 1;
  unsigned int end = x;

  if (x > 0) {
    while (start <= end) {
      ll mid = (end + start) / 2;
      if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
        return mid;
      else if (x > mid * mid)
        start = mid + 1;
      else
        end = mid - 1;
    }
  }

  return x;
}

int main() {
}
