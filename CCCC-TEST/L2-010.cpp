#include <iostream>

int pre[102];
int rank[102];
int eme[102][102];
int find(int i);
void join(int a, int b);
int main()
{
    int n, m, k, i, j, ise;
    for (i = 0; i < 102; ++i)
        pre[i] = i;
    std::cin >> n >> m >> k;
    while (m--)
    {
        std::cin >> i >> j >> ise;
        if (ise == -1)
            eme[i][j] = eme[j][i] = 1;
        else
            join(i, j);
    }
    while (k--)
    {
        std::cin >> i >> j;
        ise = (find(i) == find(j));
        if (eme[i][j])
        {
            if (ise)
                std::cout << "OK but..." << std::endl;
            else
                std::cout << "No way" << std::endl;
            continue;
        }
        if (ise)
            std::cout << "No problem" << std::endl;
        else
            std::cout << "OK" << std::endl;
    }
    return 0;
}
int find(int i)
{
    while (pre[i] != i)
        i = pre[i];
    return i;
}

void join(int a, int b)
{
    int i, j;
    i = find(a);
    j = find(b);
    pre[i] = j;
}