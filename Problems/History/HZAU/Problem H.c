#include <stdio.h>
int num[5000000];

int main(void)
{
    int N, M, ct, com, d;
    long long sum = 0;
    scanf("%d%d", &N, &M);
    for (ct = 0; ct < N; ct++)
    {
        scanf("%d", &num[ct]);
        sum += num[ct];
    }
    while (M--)
    {
        scanf("%d", &com);
        if (com == 1)
                printf("%lld\n", sum);
        else
        {
            scanf("%d", &d);
            for (sum = 0, ct = 0; ct < N; ct++)
            {
                num[ct] ^= d;
                sum += num[ct];
            }
        }
    }
    return 0;
}