#include <iostream>
int main()
{
    int n, i;
    bool ac = 0;
    std::cin >> n;
    for (i = 10; i < 100; ++i)
        if (n - 2 * (i % 10 + i / 10) < 10 && n - 2 * (i % 10 + i / 10) >= 0)
        {
            std::cout << i / 10 << i % 10 << n - 2 * (i % 10 + i / 10) << i % 10 << i / 10 << std::endl;
            ac = 1;
        }
    for (i = 100; i < 1000; ++i)
        if (n == 2 * (i / 100 + (i % 100) / 10 + i % 10))
        {
            std::cout << i / 100 << (i % 100) / 10 << i % 10 << i % 10 << (i % 100) / 10 << i / 100 << std::endl;
            ac = 1;
        }
    if (!ac)
        std::cout << "-1";
    return 0;
}