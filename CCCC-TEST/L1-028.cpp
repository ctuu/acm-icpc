#include <iostream>
bool primnum[1000000010] = {0};
void mpn(void)
{
    long long i, j;
    for (i = 2; i < 500000010; ++i)
    {
        if (primnum[i] == 1)
            continue;
        for (j = 2 * i; j < 1000000010; j += i)
            primnum[j] = 1;
    }
}
int main()
{
    int i, j;
    std::cin >> j;
    while (j--)
    {
        std::cin >> i;
        if (primnum[i])
            std::cout << "No" << std::endl;
        else
            std::cout << "Yes" << std::endl;
    }
    return 0;
}