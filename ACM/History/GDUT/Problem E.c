#include <stdio.h>
int main(void)
{
    int t, n;
    long long temp, te;
    int j, sum;
    for (scanf("%d", &t); t > 0; t--)
    {
        j = 0;
        sum = 1;
        scanf("%d", &n);
        scanf("%lld", &te);
        for (; n > 1; n--)
        {
            scanf("%lld", &temp);
            if (te < temp)
            {
                te = temp;
                sum++;
            }
        }
        printf((t == 1) ? "%d" : "%d\n\n", sum);
    }
    return 0;
}