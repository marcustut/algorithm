#include <bits/stdc++.h>

// Time Complexity: O(n^2)
// Space Complexity: O(16 * 6)
int hourglassSum(std::vector<std::vector<int>> arr)
{
    std::vector<int> sums;
    
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            // if don't have hourglass
            if (j + 2 >= arr[i].size() || i + 2 >= arr.size())
                continue;
            
            // construct the hourglass
            std::vector<int> hourglass{
                arr[i][j], arr[i][j+1], arr[i][j+2],
                arr[i+1][j+1],
                arr[i+2][j], arr[i+2][j+1], arr[i+2][j+2],
            };
            
            // calcuclate hourglass sum
            int sum = 0;
            for (int x : hourglass)
                sum += x;
            
            sums.push_back(sum);
        }
    }
    
    // find the max in all sum
    int max = sums[0];
    for (int sum : sums)
        if (sum > max)
            max = sum;
            
    return max;
}

int main()
{
    std::vector<std::vector<int>> arr =
    {
        std::vector<int>{-9,-9,-9,1,1,1},
        std::vector<int>{0,-9,0,4,3,2},
        std::vector<int>{-9,-9,-9,1,2,3},
        std::vector<int>{0,0,8,6,6,0},
        std::vector<int>{0,0,0,-2,0,0},
        std::vector<int>{0,0,1,2,4,0},
    };

    std::cout << hourglassSum(arr);
}
