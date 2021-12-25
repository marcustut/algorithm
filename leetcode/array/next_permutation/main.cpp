#include <bits/stdc++.h>
using namespace std;

void next_permutation(vector<int> &nums)
{
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

void printVec(vector<int> const &nums)
{
    cout << "{ ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << ", ";
    }
    cout << " }\n";
}

void test1()
{
    vector<int> vec1{1, 2, 3};
    vector<int> expected{1, 3, 2};
    next_permutation(vec1);
    assert(vec1 == expected);
    cout << "test1: PASSED\n";
}

void test2()
{
    vector<int> vec1{3, 2, 1};
    vector<int> expected{1, 2, 3};
    next_permutation(vec1);
    assert(vec1 == expected);
    cout << "test2: PASSED\n";
}

void test3()
{
    vector<int> vec1{4, 13, 0, 6, 2};
    vector<int> expected{4, 13, 2, 0, 6};
    next_permutation(vec1);
    assert(vec1 == expected);
    cout << "test3: PASSED\n";
}

int main()
{
    test1();
    test2();
    test3();
}
