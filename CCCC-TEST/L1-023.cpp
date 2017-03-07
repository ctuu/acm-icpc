#include <iostream>
#include <string>
int g, p, l, t;
int main()
{
    std::string ch;
    std::cin >> ch;
    for (auto s : ch)
    {
        if (s == 'G' || s == 'g')
            ++g;
        else if (s == 'P' || s == 'p')
            ++p;
        else if (s == 'L' || s == 'l')
            ++l;
        else if (s == 'T' || s == 't')
            ++t;
    }
    while ((g + p + l + t) != 0)
    {
        if (g)
        {
            std::cout << "G";
            --g;
        }
        if (p)
        {
            std::cout << "P";
            --p;
        }
        if (l)
        {
            std::cout << "L";
            --l;
        }
        if (t)
        {
            std::cout << "T";
            --t;
        }
    }
    return 0;
}