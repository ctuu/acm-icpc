#include <stdio.h>
long long num[1000001];

int main(void)
{
    int T;
    _Bool k = 0;
    long long a, b;
    long long n, i;
    for (scanf("%d", &T); T > 0; T--)
    {
        k = 0;
        scanf("%lld", &n);
        num[n] = -1;
        for (i = 0; i < n; i++)
            scanf("%lld", &num[i]);
        if (num[0] != num[1])
        {
            a = num[0];
            k = 1;
        }
        for (i = 0; i < n - 1; i++)
            if (num[i] != num[i + 1] && num[i + 1] != num[i + 2])
            {
                if (k == 1)
                    b = num[i + 1];
                else
                {
                    k = 1;
                    a = num[i + 1];
                }
            }
        if (a > b)
            {
                n = a;
                a  = b;
                b = n;
            }
        printf("%lld %lld\n",a, b);
    }
    return 0;
}
