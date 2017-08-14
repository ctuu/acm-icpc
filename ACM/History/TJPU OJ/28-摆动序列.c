#include <stdio.h>

int main(void)
{
    int n, m;
    int i, q;
    int y = 20;
    long long sum;
    long long num[32][32] = {0};
    num[1][0] = 1;
    for (m = 1; m <= y; m++)
        for (n = 1; n <= y + 1; n++)
            num[n][m] = num[n - 1][m - 1] + num[n][m - 1];
    scanf("%d", &q);
    for (sum = 0, i = 1; i < q; i++)
        sum += num[i][q];
    printf("%lld", sum * 2);
    return 0;
}