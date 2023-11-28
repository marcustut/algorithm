#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans(0);

        // Works but slow O(n^2)
        // for (size_t i = 0; i < height.size(); i++)
        //     for (size_t j = i + 1; j < height.size(); j++)
        //         ans = max(ans, (int)(j - i) * min(height[j], height[i]));

        size_t i = 0;
        size_t j = height.size() - 1;

        // Much faster O(n)
        while (i >= 0 && j < height.size())
        {
            ans = max(ans, (int)(j - i) * min(height[j], height[i]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol = Solution();
    cout << sol.maxArea(height) << endl;
    vector<int> height2 = {1, 1};
    cout << sol.maxArea(height2) << endl;
}