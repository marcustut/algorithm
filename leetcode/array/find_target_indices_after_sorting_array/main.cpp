#include <vector>
#include <iostream>
#include <assert.h>
#include <algorithm>

std::vector<int> targetIndices(std::vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end()); // O(n log n)

    std::vector<int> indices;

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] == target)
            indices.push_back(i);

    return indices;
}
