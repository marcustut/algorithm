#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  vector<int> res;
  
  // O(n^2)
  for (int i = 0; i < numbers.size(); i++) 
    for (int j = i + 1; j < numbers.size(); j++) 
      if (numbers[i] + numbers[j] == target) {
        res.push_back(i+1);
        res.push_back(j+1);
      }

  return res;
}

vector<int> twoSumFast(vector<int>& numbers, int target) {
  vector<int> res;

  int left = 0, right = numbers.size() - 1;

  // O(n)
  while (left < right) {
    if (numbers[left] + numbers[right] == target) {
      res.push_back(left+1);
      res.push_back(right+1);
      break;
    }
    else if (numbers[left] + numbers[right] < target) left++;
    else right--;
  }
  
  return res;
}

int main() {
  vector<int> tc1{2,7,11,15,16,19,234234,235543,534543};
  
  // vector<int> result = twoSum(tc1, 768777);
  vector<int> result = twoSumFast(tc1, 768777);

  for (int i = 0; i < result.size(); i++)
    cout << result[i] << ' ';
  cout << "\n";
}


