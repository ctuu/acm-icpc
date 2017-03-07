#include <iostream>
#include <iomanip>
#include <string>
int main()
{
    double i = 0, si, j;
    double result = 100;
    std::string num;
    std::cin >> num;
    si = num.size();
    if ((num[si - 1] - '0') % 2 == 0)
        result *= 2;
    for (auto s : num)
        if (s == '2')
            ++i;
    if (num[0] == '-')
    {
        result *= 1.5;
        --si;
    }
    result *= i;
    result /= si;
    std::cout << std::setprecision(2) << std::fixed << result << "%";
    return 0;
}