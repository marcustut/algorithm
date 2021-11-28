#include <vector>
#include <iostream>
using namespace std;

class SubrectangleQueries
{
public:
    vector<vector<int>> rect;

    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        rect = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for (int i = row1; i <= row2; i++)
            for (int j = col1; j <= col2; j++)
                rect[i][j] = newValue;
    }

    int getValue(int row, int col)
    {
        return rect[row][col];
    }

    void print()
    {
        for (int i = 0; i < rect.size(); i++)
        {
            for (int j = 0; j < rect[i].size(); j++)
                cout << rect[i][j] << " ";
            cout << "\n";
        }
    }
};

int main()
{
    vector<vector<int>> state({
        {1, 2, 1},
        {4, 3, 4},
        {3, 2, 1},
        {1, 1, 1},
    });
    SubrectangleQueries *obj = new SubrectangleQueries(state);
    cout << "initial state\n";
    obj->print();
    cout << endl;

    obj->updateSubrectangle(0, 0, 3, 2, 5);
    cout << "updateSubrectangle(0, 0, 3, 2, 5)\n";
    obj->print();
    cout << endl;

    obj->updateSubrectangle(3, 0, 3, 2, 10);
    cout << "updateSubrectangle(3, 0, 3, 2, 10)\n";
    obj->print();
    cout << endl;

    cout << "getValue(0, 1)\n";
    cout << obj->getValue(0, 1) << endl;
}