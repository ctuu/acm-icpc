#include <stdio.h>

int main(void)
{
    int n, k, ct;
    int a[500];
    int sum = 0;
    scanf("%d%d", &n, &k);
    for (ct = 0; ct < n; ct++)
        scanf("%d", &a[ct]);
    for (ct = 0; ct < n - 1; ct++)
    {
        if (a[ct] + a[ct + 1] < k)
        {
            sum += (k - a[ct] - a[ct + 1]);
            a[ct + 1] = k - a[ct];
        }
    }
    printf("%d\n", sum);
    for (ct = 0; ct < n; ct++)
        printf("%d ", a[ct]);
        return 0;
}