#include <iostream>
#define MMUN 1000002
int num[MMUN];
int main()
{
    int T, x, k, t, i;
    std::cin >> T;
    while (T--)
    {
        std::cin >> x >> k >> t;
        num[0] = x;
        num[1] = x-t;
        if (x %k == 0)
            num[1] = (num[1] < x/k)? num[1] :x/k;
        for (i = 2; i < MMUN; ++i)
        {
            if (num[i-1] %k == 0)
                num[i] = (num[i-1] - t < num[i-1] /k)?num[i-1] - t : num[i-1] /k;
            else
                num[i] = (num[i-1] - t < num[i-2] /k)?num[i-1] - t : num[i-2] /k;
            if(num[i] <2)
                break;
        }
        for (i = 1; num[i] > 1 && i < MMUN; ++i);
        std::cout << i<< std::endl;
    }
    return 0;
}