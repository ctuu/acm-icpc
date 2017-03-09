#include <iostream>
#include <algorithm>
#include <iomanip>
#include <array>

int main()
{
    int n, k, m, i, j;
    std::cin >> n >> k >> m;
    std::array<double, 12000> score = {0};
    std::array<int, 10> temp;
    for (j = 0; j < n; ++j)
    {
        for (i = 0; i < k; ++i)
            std::cin >> temp[i];
        std::sort(temp.begin(), temp.begin() + k);
        for (i = 1; i < k - 1; ++i)
            score[j] += temp[i];
    }
    std::sort(score.begin(), score.begin() + n);
    for (i = n - m; i < n; ++i)
    {
        if (i != n - m)
            std::cout << " ";
        std::cout << std::setprecision(3) << std::fixed << score[i] / (k - 2);
    }
    return 0;
}