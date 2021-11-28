#include <iostream>
#include <string>

int minPartitions(std::string n)
{
    int min = 1;
    for (char c : n)
        if (c - '0' > min)
            min = c - '0';
    return min;
}

int main()
{
    std::cout << minPartitions("31") << std::endl;
}