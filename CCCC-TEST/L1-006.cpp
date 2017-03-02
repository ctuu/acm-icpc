#include <iostream>
#define NU 10
int main()
{
    int i, j, n, temp = n;
    int co[NU] = {0};
    std::cin >> n;
    for (i = 2; i < NU; ++i)
    {
        temp = n;
        for (j = i; temp >=1; temp /= j, ++j)
            if (temp / j * j == temp)
                ++co[i];
            else
                break;
    }
    for (temp = 0, i = 0; i < NU; ++i)
        temp = (co[temp] >= co[i]) ? temp : i;
    if (co[temp] == 0)
        std::cout << "1\n" <<n;
    else
    {
        std::cout << co[temp] << '\n' << temp;
        --co[temp];
        for (i = temp +1 ; co[temp]; ++i, --co[temp])
            std::cout << "*" << i;
    }
    return 0;
}