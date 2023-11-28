// Avoid using built-in big integers to solve this challenge. Implement them yourself, since this is what
// you would be asked to do during a real interview.
//
// Given two binary string `a` and `b`, add them together and return the result string.
//
// Example:
// - For `a = "1000"` and `b = "111"`, the output should be `solution(a, b) = "1111"`;
// - For `a = "1"` and `b = "1"`, the output should be `solution(a, b) = "10"`;

#include <bits/stdc++.h>
using namespace std;

// [0]
// [0]
// ---
// [0] = 0 (bit = 0, carry = 0)

// [0]
// [1]
// ---
// [1] = 1 (bit = 1, carry = 0)

//   [1]
//   [1]
// -----
// [1,0] = 2 (bit = 0, carry = 1)

//   [1]
//   [1]
//   [1]
// -----
// [1,1] = 3 (bit = 1, carry = 1)

pair<int, int> handle_sum(int sum)
{
    switch (sum)
    {
    case 0:
        return make_pair(0, 0);
    case 1:
        return make_pair(1, 0);
    case 2:
        return make_pair(0, 1);
    case 3:
        return make_pair(1, 1);
    default:
        throw runtime_error("Should not have sum not in range [0, 3]");
    }
}

string solution(string a, string b)
{
    string bits;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int idx = max(i, j);

    int bit, carry = 0;

    // Process the bits together from the very end
    while (idx >= 0)
    {
        int x1 = i >= 0 ? a[i] - '0' : 0;
        int x2 = j >= 0 ? b[j] - '0' : 0;

        tie(bit, carry) = handle_sum(x1 + x2 + carry);

        bits = to_string(bit) + bits;
        i--, j--, idx--;
    }

    // Process the leftovers
    while (bit != 0 || carry != 0)
    {
        tie(bit, carry) = handle_sum(carry);
        bits = to_string(bit) + bits;
    }

    // Clean up the leading zeroes
    while (bits[0] == '0' && bits.size() > 1)
        bits.erase(bits.begin());

    return bits;
}

int main()
{
    vector<pair<string, string>> tcs = {make_pair("1000", "111"), make_pair("1", "1"), make_pair("1111", "1111")};
    for (auto tc : tcs)
        cout << solution(tc.first, tc.second) << '\n';
}
