#include <iostream>
#include <vector>
int main()
{
    int n, num, max = 0;
    std::cin >> n;
    std::vector<std::vector<int>> lj;
    lj.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> num;
        int j = 0;
        while (!lj[j].empty() && lj[j].back() < num)
            ++j;
        lj[j].push_back(num);
    }
    for (auto i : lj)
        if (!i.empty())
            ++max;
    std::cout << max;
    return 0;
}