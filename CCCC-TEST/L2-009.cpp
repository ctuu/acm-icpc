#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>

struct redbag
{
    int id;
    double money = 0;
    int time = 0;
};
bool compare(redbag a, redbag b);
int main()
{
    int n, k, i, j, pr, spr;
    std::array<redbag, 10000> mon;
    std::cin >> n;
    for (i = 0; i < n; ++i)
    {
        mon[i].id = i + 1;
        std::cin >> k;
        spr = 0;
        while (k--)
        {
            std::cin >> j >> pr;
            mon[j - 1].money += pr;
            ++mon[j].time;
            spr += pr;
        }
        mon[i].money -= spr;
    }
    std::sort(mon.begin(), mon.begin() + n, compare);
    for (i = 0; i < n; ++i)
        std::cout << mon[i].id << " " << std::setprecision(2) << std::fixed << mon[i].money / 100 << std::endl;
    return 0;
}

bool compare(redbag a, redbag b)
{
    return (a.money > b.money) || (a.money == b.money && a.time > b.time)  || (a.money == b.money && a.time == b.time && a.id < b.id);
}