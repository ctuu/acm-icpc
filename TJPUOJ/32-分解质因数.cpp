#include <iostream>
bool primnum[100001] = {0};
void decompose(int i);
void mpn(void);

int main()
{
    mpn();
    int a, b, i;
    std::cin >> a >> b;
    for (i = a; i <= b; ++i)
    {
        if (!primnum[i])
        {
            std::cout << i << "=" << i << std::endl;
            continue;
        }
        std::cout << i << "=";
        decompose(i);
        std::cout << std::endl;
    }
    return 0;
}

void mpn(void)
{
    int i, j;
    for (i = 2; i < 5001; ++i)
    {
        if (primnum[i] == 1)
            continue;
        for (j = 2 * i; j < 10001; j += i)
            primnum[j] = 1;
    }
}

void decompose(int i)
{
    int te;
    for (te = 2; te <= i && primnum[i]; ++te)
    {
        if (primnum[te])
            continue;
        if (i % te == 0)
        {
            i /= te;
            std::cout << te;
            --te;
            if (primnum[i])
                std::cout << "*";
            else
                std::cout << "*" << i;
        }
    }
}