#include <iostream>
#include <iomanip>
int main()
{
    int h, m;
    char t;
    std::cin >> h >> t >> m;
    if (h < 12 || (h == 12 && m == 0))
        std::cout << "Only " << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << m << ".  Too early to Dang.";
    else
    {
        h -= 12;
        if (m)
            ++h;
        while (h--)
            std::cout << "Dang";
    }
    return 0;
}