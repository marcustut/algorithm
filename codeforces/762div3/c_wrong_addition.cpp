#include <bits/stdc++.h>
using namespace std;

string calculate_wrong_sum(string a, string s) {
  stack<int> stack;
  for (int i = 0; i < a.size(); i++)
    stack.push(a[i] - '0');

  string ans = "";

  int i = s.size() - 1;
  string curr = "";
  
  while (!stack.empty() && i >= 0) {
    cout << "i: " << i << '\n';
    curr = s[i] + curr;
    cout << "curr: " << curr << '\n';
    cout << "top: " << stack.top() << '\n';
    if (stoi(curr) - stack.top() >= 0) {
      cout << "adding " << stoi(curr) - stack.top() << '\n';
      ans = to_string(stoi(curr) - stack.top()) + ans;
      stack.pop();
      curr = "";
    }
    i--;
    cout << '\n';
  }

  bool only_zero = true;
  for (int i = 0; i < ans.size(); i++)
    if (ans[i] != '0')
      only_zero = false;

  if (!only_zero) {
    bool meet_non_zero = false;
    for (int i = 0; i < ans.size(); i++) {
      if (!meet_non_zero && ans[i] == '0') ans.erase(0, 1);
      else meet_non_zero = true;
    }
  } else {
    ans = "1" + ans;
  }

  if (!stack.empty()) return "-1";

  return ans;
}

string wrong_addition_fast(long long a, long long s) {
  // the final answer string
  string b;

  while (s > 0) {
    long long a_last = a % 10; // last digit of A
    long long s_last = s % 10; // last digit of S
    long long b_last = (10 + s_last - a_last) % 10; // last digit of difference between a_last and s_last (+10 so that no negative value)

    // see if addition is valid (last digit of A + last digit of B = last digit of S)
    if (a_last + b_last == s_last) {
      b = to_string(b_last) + b;
      a /= 10;
      s /= 10;
    } 
    // because is wrong addition, so last of S can be two digit as well (eg. 6 + 5 = 11)
    else if (a_last + b_last == s % 100) {
      b = to_string(b_last) + b;
      a /= 10;
      s /= 100;
    } 
    else
      return "-1";
  }
  
  // if a is not totally clear then it's not valid (eg. a = 123, s = 12)
  if (a != 0) return "-1";

  // remove leading zeroes '03465' -> '3465'
  while (b.size() > 1 && b.front() == '0')
    b = b.substr(1);

  return b;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, s;
    cin >> a >> s;
    cout << wrong_addition_fast(a, s) << '\n';
  }
  return 0;
}
