#include <iostream>
#include <array>
#include <iomanip>
#include <set>
void similar(std::set<int> a, std::set<int> b);
int main()
{
    int n, i, j, temp;
    std::cin >> n;
    std::array<std::set<int>, 50> snum;
    for (i = 0; i < n; ++i)
    {
        std::cin >> j;
        while (j--)
        {
            std::cin >> temp;
            snum[i].insert(temp);
        }
    }
    std::cin >> n;
    while (n--)
    {
        std::cin >> i >> j;
        similar(snum[i - 1], snum[j - 1]);
    }
    return 0;
}

void similar(std::set<int> a, std::set<int> b)
{
    double inter = 0, ast = b.size();
    std::set<int> c;
    for (auto s : a)
        if (b.count(s))
            ++inter;
        else
            ++ast;
    std::cout << std::setprecision(2) << std::fixed << inter / ast * 100 << "%" << std::endl;
    return;
}
