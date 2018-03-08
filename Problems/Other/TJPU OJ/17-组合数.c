#include <stdio.h>
int main(void)
{
    int n, m;
    long long c, d, e;
    while (~scanf("%d%d", &n, &m))
    {
        for (c = 1, d = m, e = 1; d >= m - n + 1; d--, e++)
            {
                c *= d;
                c /= e;
            }
        printf("%lld\n", c);
    }
    return 0;
}