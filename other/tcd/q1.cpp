#include <iostream>
#include <vector>
#include <cmath>

int compute_vector(std::vector<int> vec)
{
  int sum = 0;
  for (int x : vec) sum += std::pow(x, 2);
  return std::sqrt(sum);
}

std::vector<int> findShortest(const std::vector<std::vector<int>>& vectors)
{
  std::vector<int> ret {};
  int min = INT_MAX;

  for (int i = 0; i < vectors.size(); i++) {
    int local_sum = compute_vector(vectors[i]);
    if (local_sum < min) {
      min = local_sum;
      ret = vectors[i];
    }
  }

  return ret;
}

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

#ifndef RunTests
int main()
{
    std::vector<std::vector<int>> vectors {
        { 1, 1, 1, 1, 2, 4 },
        { 2, 2, 2 },
        { 3, 3, 3, 4, 5 }
    };
  
    std::vector<int> shortest = findShortest(vectors);
    printVec(shortest);
}
#endif
