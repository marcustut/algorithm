#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  if (nums.size() == 0) return 0;

  int ptr1 = 0;
  for (int ptr2 = 1; ptr2 < nums.size(); ptr2++) {
    if (nums[ptr1] == nums[ptr2]) continue;
    else {
      ptr1++;
      nums[ptr1] = nums[ptr2];
    }
  }

  return ptr1 + 1;
}

struct testcase {
  vector<int> nums;
  vector<int> expected;
};

void test() {
  vector<testcase> testcases{
    (testcase) {vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, vector<int>{0, 1, 2, 3, 4}},
    (testcase) {vector<int>{1, 1, 2}, vector<int>{1, 2}},
  };
  for (int i = 0; i < testcases.size(); i++) {
    int k = removeDuplicates(testcases[i].nums);
    for (int j = 0; j < k; j++)
      assert(testcases[i].nums[j] == testcases[i].expected[j]);
    cout << "test" << i + 1 << ": PASSED\n";
  }
}

int main() {
  test();
}
