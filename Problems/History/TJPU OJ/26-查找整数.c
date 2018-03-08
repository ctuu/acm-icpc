#include <stdio.h>
int main(void)
{
    int num[10000];
    int t, c, b, n;
    for (scanf("%d", &t), c = 0; c < t; c++)
        scanf("%d", &num[c]);
    scanf("%d", &b);
    n = -1;
    for (c = 0; c < t; c++)
        if (b == num[c])
        {
            n = c + 1;
            break;
        }
    printf("%d", n);
    return 0;
}