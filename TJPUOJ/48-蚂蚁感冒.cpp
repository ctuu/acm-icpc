#include <iostream>
int main()
{
    int n, i, sick = 0, one;
    int num[52];
    std::cin >> n;
    for (i = 0; i < n; ++i)
        std::cin >> num[i];
    one = num[0];
    for (i = 1; i < n; ++i)
    {
        if (one > 0)
        {
            if (num[i] < 0 && -num[i] > one)
                ++sick;
            if (num[i] > 0 && num[i] < one)
                ++sick;
        }
        else
        {
            if (num[i] > 0 && num[i] < -one)
                ++sick;
                if (num[i] < 0 && num[i] < one)
                ++sick;
        }
    }
    // for (i = 1; sick > 0 && i < n; ++i)
    // {
    //     if (one > 0)
    //     {
    //     }
    //     else
    //     {
            
    //     }
    // }
    std::cout << sick;
    return 0;
}