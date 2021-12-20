#include <iostream>

// O(k) where k is either a or b, whichever smaller
// O(1) space
int gcd_naive(int a, int b) {
  int current_gcd = 1;

  for (int d = 2; d <= a && d <= b; d++)
    if (a % d == 0 && b % d == 0)
      current_gcd = std::max(d, current_gcd);

  return current_gcd;
}

// O(log ab) time and space
int gcd_euclidean(int a, int b) {
  if (b == 0) return a;
  int a_prime = a % b;
  return gcd_euclidean(b, a_prime);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclidean(a, b) << std::endl;
  return 0;
}
