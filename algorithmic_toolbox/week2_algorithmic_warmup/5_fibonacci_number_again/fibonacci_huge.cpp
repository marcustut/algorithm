#include <iostream>

// fib_last_three takes only the last three digit of a fibonacci number
// eg. fib(239) = 39679027332006820581608740953902289877834488152161
//     fib_last_three(239) = 161
//
// explaination: since m <= 1000, we will only need the last 3 digit,
//               hence it is sufficient to just get '161' since '161 % 1000'
//               will also return '161'.
int fib_last_three(long long n) {
  if (n <= 1) return n;

  int prev= 0;
  int curr = 1;

  for (int i = 0; i < n - 1; i++) {
    int tmp_prev = prev;
    prev = curr;
    curr = (tmp_prev % 1000) + (curr % 1000);
  }

  return curr % 1000;
}

// let p be the picaso period's length,
// p > m and p < m*m where m >= 2 - 1st criteria
// '0, 1' is always the starting number and will not repeat in a period - 2nd criteria
// eg. '0, 1, 1, 2, 0, 2, 2, 1' - valid
//     '0, 1, 1, 2, 0, 1, 2, 1' - not valid (because 0, 1 are repeated)
// this is a O(n^2) solution in the worst case
long long pisano_period_length(long long m) {
  long long prev = 0;
  long long curr = 1;

  for (long long i = 0; i < m * m; i++) {
    long long tmp = prev;
    prev = curr;
    curr = (tmp + curr) % m;
    if (prev == 0 && curr == 1)
      return i + 1;
  }

  return 1;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
  // find the pisano period length
  long long length = pisano_period_length(m);

  // reduce n to smallest possible using pisano period length
  long long remainder = n % length;
  std::cout << "length: " << length << ", remainder: " << remainder << ", fib_last_three(remainder): " << fib_last_three(remainder) << '\n';

  // calculate fib up to smaller n
  return fib_last_three(remainder) % m;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
  if (n <= 1)
      return n;

  long long previous = 0;
  long long current  = 1;

  for (long long i = 0; i < n - 1; ++i) {
      long long tmp_previous = previous;
      previous = current;
      current = tmp_previous + current;
  }

  return current % m;
}

int main() {
  long long n, m;
  std::cin >> n >> m;
  std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
