#include <bits/stdc++.h>
using namespace std;

int maxNumberOfBalloons(string text) {
  unordered_map<char, int> required({
    {'b', 1},
    {'a', 1},
    {'l', 2},
    {'o', 2},
    {'n', 1}
  });

  unordered_map<char, int> count;
  int lowest_ratio = INT_MAX;

  for (int i = 0; i < text.size(); i++)
    if (required.find(text[i]) != required.end())
      count[text[i]]++;

  for (auto &it : required)
    if (count.find(it.first) == count.end())
      return 0;

  for (auto &it : count) {
    int ratio = floor(it.second / required[it.first]);
    if (ratio < lowest_ratio)
      lowest_ratio = ratio;
  }

  return lowest_ratio;
}

struct testcase {
  string text;
  int result;
};

void test() {
  vector<testcase> tcs({
    (testcase) {"nlaebolko", 1},
    (testcase) {"loonbalxballpoon", 2},
    (testcase) {"lloo", 0}
  });

  for (int i = 0; i < tcs.size(); i++) {
    assert(maxNumberOfBalloons(tcs[i].text) == tcs[i].result);
    cout << "test" << i + 1 << ": PASSED\n";
  }
}

int main() {
  test();
}
