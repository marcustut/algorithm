#include <bits/stdc++.h>
using namespace std;

void next_permutation(vector<int> &nums) {
  int max = nums[nums.size() - 1];

  int first_bs_index = -1;
  int second_bs_index = -1;

  // find first black sheep
  for (int i = nums.size() - 1; i > 0; i--) {
    if (nums[i-1] < nums[i]) {
      first_bs_index = i-1;
      break;
    }
  }

  // if no black sheep found (just reverse because it's the largest possible permutation)
  if (first_bs_index == -1) {
    reverse(nums.begin(), nums.end());
    return;
  }

  // find second black sheep
  for (int i = nums.size() - 1; i > first_bs_index; i--) {
    if (nums[i] > nums[first_bs_index]) {
      second_bs_index = i;
      break;
    }
  }

  swap(nums[first_bs_index], nums[second_bs_index]);

  // reverse the last part starting from first_bs_index
  reverse(nums.begin() + first_bs_index + 1, nums.end());
}

struct testcase {
  vector<int> input;
  vector<int> expected;
};

void test() {
  vector<testcase> testcases{
    {vector<int>{1,2,3}, vector<int>{1,3,2}},
    {vector<int>{3,2,1}, vector<int>{1,2,3}},
    {vector<int>{4,13,0,6,2}, vector<int>{4,13,2,0,6}},
  };
  for (int i = 0; i < testcases.size(); i++) {
    next_permutation(testcases[i].input);
    assert(testcases[i].input == testcases[i].expected);
    cout << "test" << i + 1 << ": PASSED\n";
  }
}

int main() {
  test();
}
