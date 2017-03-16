#include <iostream>
int main()
{
    int i = 3, k = 4;
    for (i = 1; i < 3; ++i)
        std::cout << std::max(i, k);
    return 0;
}