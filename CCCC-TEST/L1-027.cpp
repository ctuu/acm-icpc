#include <iostream>
#include <cmath>
bool prim(int i);
int main()
{
    int i, n;
    std::cin >> n;
    while (n--)
    {
        std::cin >> i;
        if (i > 1 && prim(i))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    return 0;
}
bool prim(int i)
{
    for (int j = 2; j <= sqrt(i); ++j )
        if (i % j == 0)
            return 0;
    return 1;
}