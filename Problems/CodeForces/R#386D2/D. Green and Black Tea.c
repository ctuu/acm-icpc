#include <stdio.h>
int main(void)
{
    int n, k, a, b;
    int t, c;
    scanf("%d%d%d%d", &n, &k, &a, &b);
    if (a <= 1 && b <= 1)
    {
        if (a)
            printf("G");
        if (b)
            printf("B");
    }
    else if (a == 0 || b == 0)
    {
        if (~a)
        {
            if (b >= k)
                while (b--)
                    printf("B");
            else
                printf("NO");
        }

        else if (~b)
        {
            if (a >= k)
                while (a--)
                    printf("G");
            else
                printf("NO");
        }
    }
    else if (a >= b)
    {
        if ((a - 1) / k > b)
            printf("NO");
        else
        {
            if (((a - 1) / k) == 0)
                c = 1;
            else
                c = b / ((a - 1) / k);
            while (n--)
            {
                for (t = 0; t < k && a > 0; t++, a--)
                    printf("G");
                for (t = 0; t < c && b > 0; t++, b--)
                    printf("B");
            }
        }
    }
    else if (b > a)
    {
        if ((b - 1) / k > a)
            printf("NO");
        else
        {
            if (((b - 1) / k) == 0)
                c = 1;
            else
                c = a / ((b - 1) / k);
            while (n--)
            {
                for (t = 0; t < k && b > 0; t++, b--)
                    printf("B");
                for (t = 0; t < c && a > 0; t++, a--)
                    printf("G");
            }
        }
    }
    return 0;
}