#include <iostream>
#include <algorithm>
int main()
{
    int n, i, total = 0;
    int num[100] = {0};
    std::cin >> n;
    for (i = 0; i < n; ++i)
        std::cin >> num[i];
    --n;
    while (n--)
    {
        std::sort(num, num + 100);
        int ta = 0, tb = 0;
        for (i = 0; i < 100; ++i)
        {
            if (num[i] == 0)
                continue;
            if (ta == 0)
            {
                ta = num[i];
                continue;
            }
            if (tb == 0)
                tb = i;
        }
        total += ta + num[tb];
        num[tb] += ta;
        num[tb - 1] = 0;
    }
    std::cout << total;
    return 0;
}