#include <vector>

std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
{
    std::vector<bool> ans(candies.size());

    int max = candies[0];
    for (int c : candies)
        if (c > max)
            max = c;

    for (int i = 0; i < candies.size(); i++)
        if (candies[i] + extraCandies >= max)
            ans[i] = true;

    return ans;
}