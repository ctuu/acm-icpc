#include <stdio.h>
#define NU 437338199
#define MPR 1000000010
_Bool prim[1000000010] = {0};
void mpn(void);
int main(void)
{
    mpn();
    printf("Hello world\n");
    for (long long i = 2; i < NU; ++i)
        if (!prim[i])
            if (NU % i == 0)
                printf("%lld\n", i);
    return 0;
}
void mpn(void)
{
    long long i, j;
    for (i = 2; i < 400000010; ++i)
    {
        if (prim[i] == 1)
            continue;
        for (j = 2 * i; j < 800000010; j += i)
            prim[j] = 1;
    }
}