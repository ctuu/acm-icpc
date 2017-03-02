#include <iostream>
#define NUM 8
int main()
{
    int maxn[NUM] = {0};
    int i, j, n, temp, te;
    std::cin >> n;
    for (i = 0; i < NUM; ++i)
        for (temp = n, j = i + 2; temp != 0 && (te = temp / j * j) == temp; temp /= j, ++j)
            ++maxn[i];
    for (n = maxn[0], i = 1; i < NUM; ++i)
        n = (n > maxn[i]) ? n : maxn[i];
    std::cout << n << "!" << maxn[n];
    for (i = 0; i < NUM; ++i)
        if (i == n)
        {
            --maxn[i];
            std::cout << i++;
            for (j = i; maxn[i] > 0; --maxn[i], ++j)
                std::cout << "*" << j;
            break;
        }
    return 0;
}