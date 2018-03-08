#include <stdio.h>

int main(void)
{
    int T, b, n, m, i;
    int a[100000];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        scanf("%d", &a[0]);
        for (i = 1, b = 1; b < n; b++, i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > a[i - 1])
                i--;
        }
        n = i;
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d", &b);
            i = n;
            while (b >= a[n - 1])
            {
                i /= 2;
                if (b > a[i])
                {
                    while (i > -1 && b > a[i])
                        i--;
                    i++;
                }
                else if (b < a[i])
                {
                    while (i < n  && b < a[i])
                        i++;
                    if (i == n)
                    i--;
                }
                b %= a[i];
            }
            printf("%d\n", b);
        }
    }
    return 0;
}