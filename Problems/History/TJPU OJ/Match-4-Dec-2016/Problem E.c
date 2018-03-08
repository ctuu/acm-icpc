#include <stdio.h>
int main(void)
{
    int T, a, b;
    for (scanf("%d", &T); T > 0; T--)
    {
        scanf("%d%d", &a, &b);
        if (a > b)
            printf("%d\n", a + a + b);
        else
            printf("%d\n", b + b + a);
    }
    return 0;
}