// You've created a new programming language.

#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> query_types, vector<vector<int>> queries)
{
    int sum(0), key_offset(0), val_offset(0);
    unordered_map<int, int> map;

    for (size_t i = 0; i < query_types.size(); i++)
    {
        string type = query_types[i];
        vector<int> query = queries[i];

        if (type == "insert")
        {
            int x = query[0];
            int y = query[1];
            map[x - key_offset] = y - val_offset;
        }
        else if (type == "get")
        {
            int x = query[0];
            sum += map[x - key_offset] + val_offset;
        }
        else if (type == "addToKey")
        {
            int x = query[0];
            key_offset += x;
        }
        else if (type == "addToValue")
        {
            int y = query[0];
            val_offset += y;
        }
        else
            throw runtime_error("unsupported query type");
    }

    return sum;
}

int main()
{
    vector<string> query_types = {"insert", "insert", "addToValue", "addToKey", "get"};
    vector<vector<int>> queries = {{1, 2}, {2, 3}, {2}, {1}, {3}};

    cout << solution(query_types, queries) << '\n';
}
