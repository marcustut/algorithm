#include <bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (string operation : operations)
        if (operation == "--X" || operation == "X--")
            x--;
        else
            x++;
    return x;
}

void test1()
{
    vector<string> operations{"--X", "X++", "X++"};
    assert(finalValueAfterOperations(operations) == 1);
    cout << "test1: PASSED\n";
}

void test2()
{
    vector<string> operations{"++X", "++X", "X++"};
    assert(finalValueAfterOperations(operations) == 3);
    cout << "test2: PASSED\n";
}

void test3()
{
    vector<string> operations{"X++", "++X", "--X", "X--"};
    assert(finalValueAfterOperations(operations) == 0);
    cout << "test3: PASSED\n";
}

int main()
{
    test1();
    test2();
    test3();
}