#include <bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    int size = nums.size();

    for (int i = 0; i < size; i++)
        nums.push_back(nums[i]);

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
    vector<int> vec1{1, 2, 3};
    vector<int> expected{1, 2, 3, 1, 2, 3};
    assert(getConcatenation(vec1) == expected);
    cout << "test1: PASSED\n";
}

int main()
{
    test1();
}