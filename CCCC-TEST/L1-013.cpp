#include <iostream>
int main()
{
    int num[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    int max = 0, i;
    std::cin >> i;
    while (i--)
        max += num[i];
    std::cout << max;
    return 0;
}