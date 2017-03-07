#include <iostream>
#include <string>
#include <vector>
#include <array>
int main()
{
    std::vector<std::string> nam(50);
    std::array <int, 50> id = {0};
    int i, j, n;
    std::cin >> n;
    for (i = 0; i < n; ++i)
        std::cin >> id[i] >> nam[i];
    for (i = 0; i < n / 2; ++i)
    {
        std::cout << nam[i] << " ";
        for (j = n - 1; j > i; --j)
        {
            if (id[i] == 0)
            {
                if (id[j] == 1)
                    break;
            }
            else if (id[i] == 1)
                if (id[j] == 0)
                    break;
        }
        id[j] = -1;
        std::cout << nam[j] << std::endl;
    }
    return 0;
}