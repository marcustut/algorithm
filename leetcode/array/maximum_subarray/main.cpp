#include <bits/stdc++.h>
using namespace std;

// O(n^2) slow solution
int max_subarray_slow(vector<int>& nums) {
  int max = nums[0];

  for (int i = 0; i < nums.size(); i++) {
    int sum = 0;
    for (int j = i; j < nums.size(); j++) {
      sum += nums[j];
      if (sum > max)
        max = sum;
    }
  }

  return max;
}

// O(n) solution
int max_subarray(vector<int>& nums) {
  int globMax = nums[0];
  int currMax = nums[0];

  for (int i = 1; i < nums.size(); i++) {
    currMax = max(currMax + nums[i], nums[i]);
    globMax = max(globMax, currMax);
  }

  return globMax;
}

int main() {
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  cout << max_subarray(nums) << endl;
  cout << max_subarray_slow(nums) << endl;
}
