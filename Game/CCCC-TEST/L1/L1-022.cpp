#include <iostream>
int main()
{
    int odd = 0, even = 0;
    int i, j;
    std::cin >> i;
    while (i--)
    {
        std::cin >> j;
        if (j % 2 == 0)
            ++even;
        else
            ++odd;
    }
    std::cout << odd << " " << even;
    return 0;
}