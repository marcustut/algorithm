#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include "utils/display.h"

const int OUT_OF_BOUNDS_LEFT = 0;
const int OUT_OF_BOUNDS_RIGHT = 101;

std::vector<std::vector<int>> diagonal_sort(const std::vector<std::vector<int>> &mat)
{
    int m = mat.size();    // num of rows
    int n = mat[0].size(); // num of cols

    std::vector<std::vector<int>> tranposed;

    // transpose (pad left & right)
    for (int i = 0; i < m; i++)
    {
        std::vector<int> row = mat[i];
        int num_pad_left = m - i - 1;
        int num_pad_right = i;
        while (num_pad_left--)
            row.insert(row.begin(), OUT_OF_BOUNDS_LEFT);
        while (num_pad_right--)
            row.push_back(OUT_OF_BOUNDS_RIGHT);
        tranposed.push_back(row);
    }

    int tn = tranposed[0].size(); // num of cols (transposed)

    std::vector<std::vector<int>> diagonals;

    // get each diagonal (column of tranposed)
    for (int i = 0; i < tranposed[0].size(); i++)
    {
        std::vector<int> diagonal;
        for (int j = 0; j < m; j++)
            diagonal.push_back(tranposed[j][i]);
        diagonals.push_back(diagonal);
    }

    // sort each diagonal
    for (auto &diagonal : diagonals)
        sort(diagonal.begin(), diagonal.end());

    std::vector<std::vector<int>> sorted;

    // put sorted diagonals back to transposed
    for (int i = 0; i < m; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < tn; j++)
            if (diagonals[j][i] != OUT_OF_BOUNDS_LEFT && diagonals[j][i] != OUT_OF_BOUNDS_RIGHT)
                row.push_back(diagonals[j][i]);
        sorted.push_back(row);
    }

    return sorted;
}

void test()
{
    std::vector<
        std::pair<
            std::vector<std::vector<int>>,
            std::vector<std::vector<int>>>>
        testcases =
            {
                std::pair<
                    std::vector<std::vector<int>>,
                    std::vector<std::vector<int>>>{
                    std::vector<std::vector<int>>{{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}},
                    std::vector<std::vector<int>>{{1, 1, 1, 1}, {1, 2, 2, 2}, {1, 2, 3, 3}}},
                std::pair<
                    std::vector<std::vector<int>>,
                    std::vector<std::vector<int>>>{
                    std::vector<std::vector<int>>{{11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}},
                    std::vector<std::vector<int>>{{5, 17, 4, 1, 52, 7}, {11, 11, 25, 45, 8, 69}, {14, 23, 25, 44, 58, 15}, {22, 27, 31, 36, 50, 66}, {84, 28, 75, 33, 55, 68}}},
            };

    int count = 1;

    for (auto tc = testcases.begin(); tc != testcases.end(); tc++)
    {
        assert(diagonal_sort(tc->first) == tc->second);
        std::cout << "test" << count << ": PASSED\n";
        count++;
    }
}

int main()
{
    test();
}