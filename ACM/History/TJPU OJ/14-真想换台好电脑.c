#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    int num[10000];
    while (~scanf("%d%d", &a, &b))
    {
        for (c = 0; c < a; c++)
            scanf("%d", &num[c]);
        for (d = 0, c = 0; c < a - 1; c++)
        {
            if ((num[c + 1] - num[c]) > b)
                d = 0;
            else
                d++;
        }
        printf("%d\n", d + 1);
    }
    return 0;
}