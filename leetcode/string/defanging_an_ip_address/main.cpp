#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address)
{
    stringstream ans;
    for (int i = 0; i < address.size(); i++)
        if (address[i] == '.')
            ans << "[.]";
        else
            ans << address[i];
    return ans.str();
}

void test1()
{
    assert(defangIPaddr("1.1.1.1") == "1[.]1[.]1[.]1");
    cout << "test1: PASSED\n";
}

void test2()
{
    assert(defangIPaddr("255.100.50.0") == "255[.]100[.]50[.]0");
    cout << "test2: PASSED\n";
}

int main()
{
    test1();
    test2();
}