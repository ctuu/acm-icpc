#include <stdio.h>
int main(void)
{
    int n, i, k, ct;
    int pro = 0;
    scanf("%d%d", &n, &k);
    k = 240 - k;
    for (ct = 0, i = 1; i <= n && k >= ct; i++)
        ct += 5 * i;
    if (k >= ct)
        printf("%d", --i);
    else
        printf("%d", i - 2);
    return 0;
}