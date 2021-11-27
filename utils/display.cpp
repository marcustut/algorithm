#include <vector>
#include <iostream>

void printVec(std::vector<int> const &nums)
{
    std::cout << "{ ";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i];
        if (i != nums.size() - 1)
            std::cout << ", ";
    }
    std::cout << " }\n";
}