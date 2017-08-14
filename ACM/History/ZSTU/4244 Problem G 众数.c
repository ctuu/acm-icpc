#include <stdio.h>
int main(void)
{
    int T, sum, nu, max, nn;
    int num[1000] = {0};
    for (scanf("%d", &T); T > 0; T--)
    {
        int num[1000] = {0};
        for (max = 1, nu = 0, scanf("%d", &sum); sum > 0; sum--)
        {
            scanf("%d", &nu);
            num[nu - 1] += 1;
            max = (max > num[nu - 1]) ? max : num[nu - 1];
        }
        nn = 0;
        for (nu = 0; nu < 1000; nu++)
        {
            if (num[nu] == max)
            {
                if (nn == 1)
                    printf(" ");
                nn = 1;
                printf("%d", nu + 1);
            }
        }
        if (T > 1)
            printf("\n");
    }
    return 0;
}