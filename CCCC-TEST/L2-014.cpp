#include <iostream>
#include <vector>
int main()
{
    int n, num, max = 1;
    std::cin >> n;
    std::vector<std::vector<int>> lj;
    lj.resize(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> num;
        int ll = 0, lr = max, mid = lr + ll / 2;
        while ( ll < lr)
        {
            if (lj[mid].back() < num)
                ll = mid;
            else
                lr = mid + 1;
            mid = lr + ll / 2;
        }
        lj[ll].push_back(num);
    }
    for (auto i : lj)
        if (!i.empty())
            ++max;
    std::cout << max;
    return 0;
}