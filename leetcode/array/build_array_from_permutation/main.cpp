#include <bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
        ans[i] = nums[nums[i]];
    return ans;
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
    vector<int> vec1{0, 2, 1, 5, 3, 4};
    vector<int> expected{0, 1, 2, 4, 5, 3};
    assert(buildArray(vec1) == expected);
    cout << "test1: PASSED\n";
}

void test2()
{
    vector<int> vec1{5, 0, 1, 2, 3, 4};
    vector<int> expected{4, 5, 0, 1, 2, 3};
    assert(buildArray(vec1) == expected);
    cout << "test2: PASSED\n";
}

int main()
{
    test1();
    test2();
}