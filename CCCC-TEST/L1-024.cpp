#include <iostream>
int main()
{
    int i;
    std::cin >> i;
    if (i <= 5)
        std::cout << i + 2;
    if (i == 6)
        std::cout << 1;
    if (i == 7)
        std::cout << 2;
    return 0;
}