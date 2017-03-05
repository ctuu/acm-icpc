#include <iostream>
int main()
{
    int j, n, m;
    char ch;
    std::cin >> n >> ch;
    m = (n + 1) / 2;
    while (m--)
    {
        for (j = n; j > 0; --j)
            std::cout << ch;
        std::cout << std::endl;
    }
    return 0;
}