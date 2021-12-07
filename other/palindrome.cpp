#include <bits/stdc++.h>

bool isPalindrome(std::string inputString, std::string trashSymbolString)
{
    std::vector<char> arr;

    for (int i = inputString.size() - 1; i >= 0; i--)
        if (trashSymbolString.find(inputString[i]) == std::string::npos)
            arr.push_back(inputString[i]);

    for (int i = 0; i < arr.size(); i--)
        if (arr[i] != arr[arr.size() - 1 - i])
            return false;

    return true;
}

int main()
{
    bool tc1 = isPalindrome("a@b!!b$a", "!@$");
    std::cout << "tc1: ";
    if (tc1)
        std::cout << "passed" << std::endl;
    else
        std::cout << "failed" << std::endl;
    bool tc2 = isPalindrome("?Aa#c", "#?");
    std::cout << "tc2: ";
    if (tc2)
        std::cout << "passed" << std::endl;
    else
        std::cout << "failed" << std::endl;
}