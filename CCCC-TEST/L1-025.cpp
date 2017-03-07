#include <iostream>
#include <string>
int main()
{
    std::string nuo, nut;
    int a = 0, b = 0, i;
    bool isa = 0;
    int isb = 0;
    std::cin >> nuo;
    getline(std::cin, nut);
    i = nuo.size();
    if (i > 4)
        isa = 1;
    else
    {
        for (auto s : nuo)
        {
            if (s < '0' || s > '9')
            {
                isa = 1;
                break;
            }
            else if (i == 4)
                a += 1000 * (s - '0');
            else if (i == 3)
                a += 100 * (s - '0');
            else if (i == 2)
                a += 10 * (s - '0');
            else if (i == 1)
                a +=  s - '0';
            else
            {
                isa = 1;
                break;
            }
            --i;
        }
    }
    i = nut.size();
    if (i > 5)
        isb = 1;
    else
    {
        for (auto s : nut)
        {
            if (s == ' ' && isb == -1)
            {
                isb = 1;
                break;
            }
            else if (s == ' ' && isb == 0)
                isb = -1;
            else if (s < '0' || s > '9')
            {
                isb = 1;
                break;
            }
            else if (i == 4)
                b += 1000 * (s - '0');
            else if (i == 3)
                b += 100 * (s - '0');
            else if (i == 2)
                b += 10 * (s - '0');
            else if (i == 1)
                b +=  s - '0';
            else
            {
                isb = 1;
                break;
            }
            --i;
        }
    }
    if (a > 1000 || a < 1)
        isa = 1;
    if (b > 1000 || b < 1)
        isb = 1;
    if (isa)
        std::cout << "?";
    else
        std::cout << a;
    std::cout << " + ";
    if (isb == 1)
        std::cout << "?";
    else
        std::cout << b;
    std::cout << " = ";
    if (isa == 1 || isb == 1)
        std::cout << "?";
    else
        std::cout << a + b;
    return 0;
}