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

void print2DVec(std::vector<std::vector<int>> const &nums)
{
    std::cout << "{\n";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << "  { ";
        for (int j = 0; j < nums[i].size(); j++)
        {
            std::cout << nums[i][j] << " ";
        }
        std::cout << "},\n";
    }
    std::cout << "}\n";
}