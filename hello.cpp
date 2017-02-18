#include <iostream>
bool primnum[100001] = {0};
int main()
{
    int i, j;
    for (i = 2; i < 5001; i++)
    {
        if (primnum[i] == 1)
            continue;
        for (j = 2 * i; j < 15000; j += i)
            primnum[j] = 1;
    }
    for (i = 0; i < 1001; ++i)
        if (!primnum[i])
            std::cout << i << "  ";
    return 0;
}