#include <stdio.h>
int main(void)
{
    int T, n, k;
    for (scanf("%d", &T); T > 0; T--)
    {
        scanf("%d%d", &n, &k);
        if (k == 1 || k == n)
            printf("BH\n");
        else if (n == 3)
            printf("BH\n");
        else if ((n - 3) % 2 == 0)
            printf("BH\n");
        else
            printf("LYF\n");
    }
    return 0;
}