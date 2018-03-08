#include <iostream>
#include <vector>
int main()
{
    int n, num, max = 0;
    std::cin >> n;
    std::vector<std::vector<int>> lj;
    lj.resize(n);
    while (n--)
    {
        std::cin >> num;
        int ll = 0, lr = max - 1;
        if (lj[ll].empty() || lj[lr].back() < num)
        {
            lj[max].push_back(num);
            ++max;
        }
        else
        {
            while (ll < lr)
            {
                if (lj[(ll + lr) / 2].back() > num)
                    lr = (ll + lr) / 2;
                else
                    ll = (ll + lr) / 2 + 1;
            }
            lj[ll].push_back(num);
        }
    }
    std::cout << max;
    return 0;
}