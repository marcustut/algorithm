#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
  // if x is negative, it can never be a palindrome
  if (x < 0)
    return false;

  long long original = x;
  long long lastDigit = 0;
  long long reversed = 0;

  // reverse x 
  while (x > 0) {
    // get the last digit
    lastDigit = x % 10;
    // add last digit with respect to its ones/tens/hundreds
    reversed = (reversed * 10) + lastDigit;
    // take away the last digit from x
    x = x / 10;
  }

  return reversed == original;
}

bool isPalindromeString(int x) {
  string s = to_string(x);

  int left = 0, right = s.size() - 1;

  while (left <= right) {
    if (s[left] != s[right]) return false;
    left++;
    right--;
  }

  return true;
}

struct testcase {
  int x;
  bool answer;
};

void test() {
  vector<testcase> testcases{
    (testcase) {121, true},
    (testcase) {-121, false},
    (testcase) {10, false},
    (testcase) {212, true},
  };
  for (int i = 0; i < testcases.size(); i++) {
    assert(isPalindromeString(testcases[i].x) == testcases[i].answer);
    cout << "test " << i + 1 << ": passed\n";
  }
}

int main() {
  test();
}


// 1234 % 10 = 4
// 123 % 10 = 3
// 12 % 10 = 2
// 1 % 10 = 1



