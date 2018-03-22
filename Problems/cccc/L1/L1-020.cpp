#include <iostream>
#include <array>
#include <iomanip>
int main()
{
    int nuof, i, temp, j;
    std::array<int, 100000> judge = {0};
    std::cin >> nuof;
    while (nuof--)
    {
        std::cin >> j;
        i = j;
        while (i--)
        {
            std::cin >> temp;
            if (j > 1)
                ++judge[temp];
            ++judge[temp];
        }
    }
    std::cin >> nuof;
    i = 0;
    while (nuof--)
    {
        std::cin >> temp;
        if (judge[temp] < 2 && judge[temp] > -1)
        {
            if (i == 1)
                std::cout << " ";
            std::cout <<std::setw(5)<<std::setfill('0')<< temp;
            i = 1;
            judge[temp] = -1;
        }
    }
    if (i == 0)
        std::cout << "No one is handsome";
    return 0;
}