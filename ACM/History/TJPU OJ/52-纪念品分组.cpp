#include <iostream>
#include <algorithm>
int main()
{
    int w, n, i, j;
    int pi[30002];
    std::cin >> w >> n;
    for (i = 0; i < n; ++i)
        std::cin >> pi[i];
    std::sort(pi, pi + n);
    int numg = n;
    for (i = n - 1, j = 0; i > 0 && i > j; --i)
    {
        if (pi[i] >= w)
            continue;
        if (pi[i] + pi[j] <= w && i > j)
        {
            --numg;
            ++j;
        }
    }
    std::cout << numg;
    return 0;
}