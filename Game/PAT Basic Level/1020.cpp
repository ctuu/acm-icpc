#include <iostream>
#include <algorithm>
#include <array>
#include <iomanip>
struct mooncake
{
    double quan = 0;
    double price = 0;
};
bool jud(mooncake a, mooncake b);
int main()
{
    int n, d, i;
    double sum = 0;
    std::cin >> n >> d;
    std::array<mooncake, 1200> moca;
    for ( i = 0; i < n; ++i)
        std::cin >> moca[i].quan;
    for ( i = 0; i < n; ++i)
        std::cin >> moca[i].price;
    std::sort (moca.begin(), moca.begin() + n, jud);
    for (i = 0; d > 0 && i < n; ++i)
    {
        if (moca[i].quan > d)
        {
            sum += d * moca[i].price / moca[i].quan;
            d = 0;
        }
        else
        {
            sum += moca[i].price;
            d -= moca[i].quan;
        }
    }
    std::cout << std::setprecision(2) << std::fixed << sum;
    return 0;
}

bool jud(mooncake a, mooncake b)
{
    return a.price / a.quan > b.price / b.quan;
}