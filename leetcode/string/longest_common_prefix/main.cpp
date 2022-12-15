#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) return strs[0];

    vector<string> orig;

    copy(strs.begin(), strs.end(), back_inserter(orig));

    sort(strs.begin(), strs.end(), [](string& a, string& b) {
        return a.size() < b.size();
    });

    string ret = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        for (int j = 0; j < strs[i].length(); j++) {
            if (ret[j] == strs[i][j]) continue;
            else ret = ret.substr(0, j);
        }
    }

    return ret;
}

void test1()
{
    vector<string> vec{"flower", "flow", "flight"};
    assert(longestCommonPrefix(vec) == "fl");
    cout << "test1: PASSED\n";
}

void test2()
{
    vector<string> vec{"dog","racecar","car"};
    assert(longestCommonPrefix(vec) == "");
    cout << "test2: PASSED\n";
}

void test3()
{
    vector<string> vec{"a"};
    assert(longestCommonPrefix(vec) == "a");
    cout << "test3: PASSED\n";
}

void test4()
{
    vector<string> vec{"ab", "a"};
    assert(longestCommonPrefix(vec) == "a");
    cout << "test4: PASSED\n";
}

void test5()
{
    vector<string> vec{"flower","flower","flower","flower"};
    assert(longestCommonPrefix(vec) == "flower");
    cout << "test5: PASSED\n";
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
