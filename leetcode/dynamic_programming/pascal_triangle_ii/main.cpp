#include <bits/stdc++.h>
#include <utils/display.h>
using namespace std;

// TODO: Revisit this (to understand how the calculation works)
vector<int> get_row(int row_index)
{
    vector<int> row(row_index + 1);
    row[0] = 1;
    for (int i = 1; i <= row_index; i++)
    {
        for (int j = i / 2; j >= 1; --j)
        {
            row[j] += row[j - 1];
            row[i - j] = row[j];
        }
        row[i] = 1;
    }

    return row;
}

int main()
{
    printVec(get_row(4));
    return 0;
}