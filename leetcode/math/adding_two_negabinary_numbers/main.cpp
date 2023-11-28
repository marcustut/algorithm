// Problem: https://leetcode.com/problems/adding-two-negabinary-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  pair<int, int> handleSum(int sum) {
    int bit = 0;
    int carry = 0;

    switch (sum) {
    case 0:
      bit = 0;
      carry = 0;
      break;
    case 1:
      bit = 1;
      carry = 0;
      break;
    case 2:
      bit = 0;
      carry = -1;
      break;
    case 3:
      bit = 1;
      carry = -1;
      break;
    case -1:
      bit = 1;
      carry = 1;
      break;
    default:
      throw runtime_error("Should not have sum not in range [-1,3]");
    }

    return make_pair(bit, carry);
  }

  vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2) {
    vector<int> bits;
    int i = (int)arr1.size() - 1;
    int j = (int)arr2.size() - 1;
    int idx = max(i, j);

    int bit = 0;
    int carry = 0;

    // Process the arithmetic for all given bits
    while (idx >= 0) {
      int x1 = i >= 0 ? arr1[i] : 0;
      int x2 = j >= 0 ? arr2[j] : 0;

      tie(bit, carry) = handleSum(x1 + x2 + carry);

      bits.push_back(bit);
      i--;
      j--;
      idx--;
    }

    // Process the leftovers
    while (bit != 0 || carry != 0) {
      tie(bit, carry) = handleSum(carry);
      bits.push_back(bit);
    }

    // Reverse the bits (because we're insert at the back)
    reverse(bits.begin(), bits.end());

    // Clean up the leading zeroes
    while (bits[0] == 0 && bits.size() > 1)
      bits.erase(bits.begin());

    return bits;
  }
};

int main() {
  vector<int> arr1 = {1};
  vector<int> arr2 = {1, 1};
  Solution sol;

  auto bits = sol.addNegabinary(arr1, arr2);
  cout << "There are " << bits.size() << " bits.\n";
  for (auto bit : bits)
    cout << bit << " ";
  cout << "\n";
}

// [0]
// [0]
// ---
// [0] = 0 (bit = 0, carry = 0)

// [0]
// [1]
// ---
// [1] = 1 (bit = 1, carry = 0)

//     [1]
//     [1]
// -------
// [1,1,0] = 4 - 2 = 2 (bit = 0, carry = -1)

//     [1]
//     [1]
//     [1]
// -------
// [1,1,1] = 4 - 2 + 1 = 3 (bit = 1, carry = -1)

//    [-1]
// -------
//  [1, 1] (bit = 1, carry = 1)
