#include <stdio.h>
int main(void)
{
    int x, y, n, m;
    while (~scanf("%d%d", &y, &x))
    {
        long long num[32][32] = {0};
        num[1][0] = 1;
        for (m = 1; m <= y; m++)
            for (n = 1; n <= y + 1; n++)
                num[n][m] = num[n - 1][m - 1] + num[n][m - 1];
        printf("%lld\n", num[x + 1][y]);
    }
    return 0;
}