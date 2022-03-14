#include <bits/stdc++.h>
using namespace std;

struct testcase {
  int k;
  vector<int> input;
  vector<int> expected;
};
vector<testcase> testcases{
  {3, vector<int>{1,2,3,4,5,6,7}, vector<int>{5,6,7,1,2,3,4}},
  {2, vector<int>{-1,-100,3,99}, vector<int>{3,99,-1,-100}},
};

void rotate_v1(vector<int>& nums, int k) {
  // make a clone of the original vector
  vector<int> clone = vector<int>(nums);

  // mod k will remove extra iterations
  k = k % nums.size();

  // mutate elements up to k
  for (int i = 0; i < k; i++)
    nums[i] = clone[nums.size() - k + i];

  // mutate elements after k
  for (int i = k; i < nums.size(); i++)
    nums[i] = clone[i - k];
}

void rotate_v2(vector<int>& nums, int k) {
  // to store temp element
  int temp;

  // mod k will remove extra iterations
  k = k % nums.size();

  // reverse the whole array
  for (int i = 0; i < nums.size() / 2; i++) {
    temp = nums[i];
    nums[i] = nums[nums.size() - 1 - i];
    nums[nums.size() - 1 - i] = temp;
  }

  // reverse elements up to k
  for (int i = 0; i < k / 2; i++) {
    temp = nums[i];
    nums[i] = nums[k - 1 - i];
    nums[k - 1 - i] = temp;
  }

  // reverse elements after k
  for (int i = 0; i < (nums.size() - k) / 2; i++) {
    temp = nums[k + i];
    nums[k + i] = nums[nums.size() - 1 - i];
    nums[nums.size() - 1 - i] = temp;
  }
}

void rotate_v3(vector<int>& nums, int k) {
  k = k % nums.size();
  
  for (int i = 0; i < nums.size() / 2; i++)
    swap(nums[i], nums[nums.size() - 1 - i]);
  
  for (int i = 0; i < k / 2; i++)
    swap(nums[i], nums[k - 1 - i]);
  
  for (int i = 0; i < (nums.size() - k) / 2; i++)
    swap(nums[k + i], nums[nums.size() - 1 - i]);
}

void test() {
  vector<testcase> tcs(testcases);
  cout << "Testing rotate_v1\n";
  for (int i = 0; i < tcs.size(); i++) {
    rotate_v1(tcs[i].input, tcs[i].k);
    assert(tcs[i].input == tcs[i].expected);
    cout << "Test Case " << i + 1 << ": PASSED\n";
  }
}

void test2() {
  vector<testcase> tcs(testcases);
  cout << "Testing rotate_v2\n";
  for (int i = 0; i < tcs.size(); i++) {
    rotate_v2(tcs[i].input, tcs[i].k);
    assert(tcs[i].input == tcs[i].expected);
    cout << "Test Case " << i + 1 << ": PASSED\n";
  }
}

void test3() {
  vector<testcase> tcs(testcases);
  cout << "Testing rotate_v3\n";
  for (int i = 0; i < tcs.size(); i++) {
    rotate_v3(tcs[i].input, tcs[i].k);
    assert(tcs[i].input == tcs[i].expected);
    cout << "Test Case " << i + 1 << ": PASSED\n";
  }
}

int main() {
  test();
  test2();
  test3();
}
