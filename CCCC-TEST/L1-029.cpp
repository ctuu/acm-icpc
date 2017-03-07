#include <iostream>
#include <iomanip>
int main()
{
    double a;
    std::cin >> a;
    std::cout << std::setprecision(1) << std::fixed << (a - 100) * 1.8;
    return 0;
}