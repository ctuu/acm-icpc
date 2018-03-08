#include <stdio.h>
int main(void)
{
    int T, n, k;
    int ct, sum;
    int gr = 0;
    _Bool isM;
    char num[100000];
    for (scanf("%d", &T); T > 0; T--)
    {
        isM = 0;
        gr = 0;
        scanf("%d%d", &n, &k);
        while (getchar() != '\n')
            continue;
        for (sum = 0, ct = 0; ct < n; ct++)
        {
            scanf("%c", &num[ct]);
            if (num[ct] == 'a')
            {
                sum += 1;
                isM = 1;
                gr += 1;
            }
            else if (num[ct] == 'b')
            {
                if (isM)
                {
                    sum += 1;
                    gr = 0;
                }
                sum += 1;
                isM = 0;
                gr += 1;
            }
            else if (num[ct] == 'c')
            {
                if (gr >= k)
                {
                    sum += 1;
                    gr = 0;
                }
                isM = 0;
                sum += 1;
                gr += 1;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}