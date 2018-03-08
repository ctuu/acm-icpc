#include <stdio.h>
int sum = 1000002;

typedef struct number
{
    int xx;
    int aa;
} N;

N num[1000000];
void dp(int x, int k, int t, int a);
int main(void)
{
    int T;
    int X, k, t, ct, i;
    for (scanf("%d", &T); T > 0; T--)
    {
        sum = 1000002;

        scanf("%d%d%d", &X, &k, &t);
        ct = 1;
        num[0].xx = X;
        num[0].aa = 0;
        for (i = 0; i < ct; i++)
        {
            if (num[i].xx <= 1)
            {
                sum = (sum < num[i].aa) ? sum : num[i].aa;
                continue;
            }
            if (num[i].aa > sum)
                continue;
            ++ct;
            num[ct - 1].xx = num[i].xx - t;
            num[ct - 1].aa = num[i].aa + 1;
            ++ct;
            if (num[i].xx % k != 0)
            {
                num[ct - 1].xx = num[i].xx / k;
                num[ct - 1].aa = num[i].aa + 2;
            }
            else
            {
                num[ct - 1].xx = num[i].xx / k;
                num[ct - 1].aa = num[i].aa + 1;
            }
        }

        printf("%d\n", sum);
    }
    return 0;
}