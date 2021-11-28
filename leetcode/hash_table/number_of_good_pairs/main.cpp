#include <vector>
#include <iostream>
#include <assert.h>
#include <unordered_map>

// This solution is slow as it goes through each element and
// check it againts all the other elements. (Brute Force)
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int numIdenticalPairs(const std::vector<int> &nums)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < nums.size(); j++)
            if (nums[i] == nums[j] && i < j)
                count++;
    return count;
}

// This solution is the fastest where it only iterate through
// the input one time. It works by keeping track the number of
// equivalent elements using a hashtable.
// Time Complexity: O(n)
// Space Complexity: O(n)
int numIdenticalPairsFast(const std::vector<int> &nums)
{
    int count = 0;
    std::unordered_map<int, int> map; // or std::vector<int> map(101);
    for (const int num : nums)
        count += map[num]++;
    return count;
}

void test()
{
    std::vector<std::pair<std::vector<int>, int>> testcases =
        {
            std::pair<std::vector<int>, int>{std::vector<int>{1, 2, 3, 1, 1, 3}, 4},
            std::pair<std::vector<int>, int>{std::vector<int>{1, 1, 1, 1}, 6},
            std::pair<std::vector<int>, int>{std::vector<int>{1, 2, 3}, 0},
        };

    int count = 1;

    for (auto tc = testcases.begin(); tc != testcases.end(); tc++)
    {
        assert(numIdenticalPairs(tc->first) == tc->second);
        assert(numIdenticalPairsFast(tc->first) == tc->second);
        std::cout << "test" << count << ": PASSED\n";
        count++;
    }
}

int main()
{
    test();
}