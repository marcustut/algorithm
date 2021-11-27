#include <bits/stdc++.h>
#include "utils/display.h"
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2 - (n*2))
vector<vector<int>> generate_pascal_triangle(int numRows)
{
    vector<vector<int>> pascal_triangle;

    // pascal triangle only works for 1 and above
    if (numRows < 1)
        return pascal_triangle;

    // init first row
    vector<int> first_row = {1};
    pascal_triangle.push_back(first_row);

    // for each row
    for (int i = 1; i < numRows; i++)
    {
        // create a new vector, add '1' at front
        vector<int> row = {1};

        // for each col calculate its value
        for (int j = 0; j < (i - 1); j++)
            row.push_back(pascal_triangle[i - 1][j] + pascal_triangle[i - 1][j + 1]);

        // add '1' at the back
        row.push_back(1);
        // push current row to the main vector
        pascal_triangle.push_back(row);
    }

    return pascal_triangle;
}

int main()
{
    auto tri = generate_pascal_triangle(10);

    for (int i = 0; i < tri.size(); i++)
        printVec(tri[i]);

    return 0;
}