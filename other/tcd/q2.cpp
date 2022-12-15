#include <algorithm>
#include <iostream>

struct Battery
{
    float charge = 0.0f;
};

void charge(Battery* battery, float charge)
{
    battery->charge += charge;
}

#ifndef RunTests
int main()
{
    Battery battery;
    charge(&battery, 1.0f);
    std::cout << battery.charge << std::endl;
}
#endif
