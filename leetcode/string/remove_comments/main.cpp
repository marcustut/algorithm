#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> result;
        string out = "";
        bool block = false;

        for (string line : source)
        {
            for (size_t i = 0; i < line.size(); i++)
            {
                size_t len = i == line.size() - 1 ? 1 : 2; // To prevent out of bounds at last char
                string t = line.substr(i, len);

                if (block)
                {
                    if (t == "*/")
                        block = false, i++;

                    continue; // Continue because we ignore block comments entirely
                }

                if (t == "/*")
                    block = true, i++;
                else if (t == "//")
                    break; // We ignore rest of the line since anything after '//' is ignored.
                else
                    out += line[i];
            }

            if (!out.empty() && !block)
            {
                result.push_back(out); // Commit the line
                out = "";              // Reset to clean state
            }
        }

        return result;
    }
};

int main()
{
    // vector<string> source = {
    //     "/*Test program */",
    //     "int main()",
    //     "{ ",
    //     "  // variable declaration ",
    //     "int a, b, c;",
    //     "/* This is a test",
    //     "   multiline  ",
    //     "   comment for ",
    //     "   testing */",
    //     "a = b + c;",
    //     "}"};
    vector<string> source = {
        "// Test Program",
        "/*Test program */",
        "int main()",
        "{ ",
        "  // variable declaration ",
        "int a, b, c;",
        "int x = 0; /* haha */",
        "int y = 0; // haha",
        "int z = 0; /* haha",
        "loll */",
        "int xy = 0; /* haha",
        "loll */  ",
        "int xz = 0; /* haha",
        "loll */ int zz = 0; // haha",
        "/* This is a test",
        "   multiline  ",
        "   comment for ",
        "   testing */",
        "a = b + c;",
        "}"};
    // vector<string> source = {
    //     "a/*comment",
    //     "line",
    //     "more_comment*/b"};
    // vector<string> source = {
    //     "main() {",
    //     "/* here is commments",
    //     " // still comments */",
    //     " double s = 33;",
    //     " cout << s;",
    //     "}"};
    // vector<string> source = {
    //     "a//*b/*/c",
    //     "blank",
    //     "d/*/e/*/f"};
    Solution sol;

    vector<string> cleaned_sources = sol.removeComments(source);

    for (auto cleaned_source : cleaned_sources)
        cout << cleaned_source << '\n';

    return 0;
}

// Assumption 1: The syntax of source code given is valid.

// Case 1: Line comments: '//'
// Action 1a: if '//' is the starting character, delete the entire line.
// Action 1b: if '//' is not the starting character, delete all chracters after it.

// Case 2: Line comments: '/*' and '*/' in one line
// Action 2a: if '/*' is the starting chracter, delete the entire line.
// Action 2b: if '/*' is not the starting character, delete from '/*' to '*/'.

// Case 3: Block comments: '/*' in one line -> Delete this line and keep deleting lines until found '*/'.
// Action 3a: if '/*' is the starting character, delete the entire line.
// Action 3b: if '/*' is not the starting chracter, delete the line from '*/' to end.
// Action 3c: if '*/' is the ending character, delete the entire line.
// Action 3d: if '*/' is not the ending character, delete up to it.
