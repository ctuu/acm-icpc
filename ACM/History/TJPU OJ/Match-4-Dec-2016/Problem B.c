#include <stdio.h>
int main(void)
{
    int T, N , a, b;
    int sum;
    for (scanf("%d", &T); T > 0; T--)
    {
        for (sum = 0, scanf("%d", &N);N > 0; N--)
        {
            scanf("%d%d", &a, &b);
            sum += a * b;
        }
        printf("%d\n", sum);
    }
    return 0;
}