//7 10
//252
#include <iostream>
int main()
{
    int pass[32][32] = {0};
    int n, m, i, j;
    std::cin >> n >> m;
    pass[0][0] = 1;
    for (i = 0; i <= m; ++i)
        for (j = 0; j < n; ++j)
        { 
            if (pass[i][j] > 0)
            {
                if (j == 0)
                {
                    pass[i + 1][1] += 1;
                    pass[i + 1][n - 1] +=1;
                }
                else if (j == n - 1)
                {
                    pass[i + 1][0] +=1;
                    pass[i + 1][n - 2] += 1;
                }
                else
                {
                    pass[i + 1][j + 1] +=1;
                    pass[i + 1][j - 1] +=1;
                }
            }
        }
    std::cout << pass[m][0] << std::endl;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << pass[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}