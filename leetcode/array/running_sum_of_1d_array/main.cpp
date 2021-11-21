#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
        nums[i] += nums[i - 1];
    return nums;
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
    vector<int> nums{1, 2, 3, 4};
    vector<int> expected{1, 3, 6, 10};
    assert(runningSum(nums) == expected);
    cout << "test1: PASSED\n";
}

void test2()
{
    vector<int> nums{1, 1, 1, 1, 1};
    vector<int> expected{1, 2, 3, 4, 5};
    assert(runningSum(nums) == expected);
    cout << "test2: PASSED\n";
}

void test3()
{
    vector<int> nums{3, 1, 2, 10, 1};
    vector<int> expected{3, 4, 6, 16, 17};
    assert(runningSum(nums) == expected);
    cout << "test3: PASSED\n";
}

int main()
{
    test1();
    test2();
    test3();
}