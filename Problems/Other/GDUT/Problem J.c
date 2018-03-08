#include <stdio.h>
long long pn[15000] = {0};
long long dpn[100000005] = {0};

void mpn(void);
int main(void)
{
    mpn();
    long long i, T, j;
    long long n;
    for (i = 0; i < 10001; i++)
    {
        if (pn[i] == 0)
            dpn[i * i] = 1;
    }
    for (scanf("%lld", &T); T > 0; T--)
    {
        scanf("%lld", &n);
        for (i = n, j = n;; i--, j++)
        {
            if (dpn[i] == 1)
            {
                printf("%lld\n", i);
                break;
            }
            if (dpn[j] == 1)
            {
                printf("%lld\n", j);
                break;
            }

        }
    }
    return 0;
}

void mpn(void)
{
    int i, j;
    for (i = 2; i < 7500; i++)
        for (j = 2 * i; j < 15000; j += i)
        {
            pn[j] = i;
        }
}