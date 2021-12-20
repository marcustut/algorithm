#include <iostream>

// the better way to solve this is that to find GCD(a,b).
// Because we know that the upper bound for LCM(a,b) is a*b,
// and we know for sure that any common multiple of a and b
// can be divided by a common divisor, so the smallest common
// multiple would be the UPPER_BOUND divided by the GREATEST_COMMON_DIVISOR,
// hence -> a*b / GCD(a,b)

// O(log ab)
long long gcd(int a, int b) {
  if (b == 0) return a;
  long long a_prime = a % b;
  return gcd(b, a_prime);
}

// since time complexity of GCD is O(log ab)
// hence time complexity for LCM is also O(log ab)
long long lcm_fast(int a, int b) {
  return ((long long) a * b) / gcd(a, b);
}

// O(ab)
long long lcm_naive(int a, int b) {
  for (long long i = 0; i <= (long long) a * b; i++)
    if (i % a == 0 && i % b == 0)
      return i;

  return (long long) a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
