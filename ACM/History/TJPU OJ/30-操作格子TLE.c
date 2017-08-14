#include <stdio.h>
int main(void)
{
    int num[100001];
    int n, m, p, x, y, i, max;
    long long sum;
    scanf("%d%d", &n, &m);
    for (x = 1; x <= n; x++)
        scanf("%d", &num[x]);
    while (m--)
    {
        scanf("%d%d%d", &p, &x, &y);
        switch (p)
        {
        case 1:
            num[x] = y;
            break;
        case 2:
            for (sum = 0; x <= y; x++)
                sum += num[x];
            printf("%lld\n", sum);
            break;
        case 3:
            for (max = 0; x <= y; x++)
                max = (max > num[x]) ? max : num[x];
            printf("%d\n", max);
            break;
        }
    }
    return 0;
}