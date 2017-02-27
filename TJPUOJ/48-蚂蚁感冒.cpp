#include <iostream>
int main()
{
    int n, i, temp, fir, sick = 1;
    int road[101];
    std::cin >> n;
    for (i = 0; i < n; ++i)
    {
        std::cin >> temp;
        if (i == 0)
            fir = temp;
        if (temp > 0)
            road[temp] = 1;
        else
            road[temp] = -1;
    }
    if (road[fir] > 0)
        ++road[fir];
    else
        --road[fir];

    while (n)
        for (i = 0; i < 101; ++i)
        {
            if (road[i] > 0)
            {
                if (road[i + 1] == 0)
                {
                    ++road[i + 1];
                    --road[i];
                }
                else if (road[i + 1] == 1 || road[i + 1] == -1)
                {
                    road[i + 1] = -road[i + 1];
                    road[i] = -road[i];
                }
                else if (road[i + 1] == 2 || road[i + 1] == -2)
                {
                    road[i + 1] = -road[i + 1];
                    road[i] = -road[i];
                    ++sick;
                }
            }

            else if (road[i] < 0)
            {
                if (road[i - 1] == 0)
                {
                    --road[i - 1];
                    ++road[i];
                }
                else if (road[i - 1] == 1 || road[i - 1] == -1)
                {
                    road[i - 1] = -road[i - 1];
                    road[i] = -road[i];
                }
                else if (road[i - 1] == 2 || road[i - 1] == -2)
                {
                    road[i - 1] = -road[i - 1];
                    road[i] = -road[i];
                    ++sick;
                }
            }
            if (i == 0 || i == 101)
            {
                road[i] = 0;
                --n;
            }
        }
    std::cout << sick;
    return 0;
}