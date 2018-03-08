#include <stdio.h>
int main(void)
{
    long long n, a, b, c, d, e, f;
    int i;
    long long T, min, max;
    for (scanf("%lld", &T); T > 0; T--)
    {
        scanf("%lld%lld%lld%lld", &n, &a, &b, &c);

        min = 10000000000;
        max = (a > b) ? a : b;
        max = (max > c) ? max : c;
        if (n == 0)
            i = 4;
        else if (n < 4)
            i = n;
        else if (n % 4 == 0)
            i = 0;
        else
            i = n % 4;
        d = 0;
        e = 0;
        f = 0;
        for (d = 0; d <= 4; d++, e = 0, f = 0)
            for (e = 0; e <= 4; e++, f = 0)
                for (f = 0; f <= 4; f++)
                {
                    if ((d + 2 * e + 3 * f + i) % 4 == 0)
                        min = (min < a * d + b * e + c * f) ? min : a * d + b * e + c * f;
                }

        printf("%lld\n", min);
    }
    return 0;
}