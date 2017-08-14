#include <stdio.h>
int main(void)
{
    int n, cost, ct, max;
    int cit[100];
    scanf("%d", &n);
    for (ct = 0, max = 0; ct < n; ++ct)
    {
        scanf("%d", &cit[ct]);
        max = (max > cit[ct]) ? max : cit[ct];
    }
    for (ct = 0, cost = 0; ct < n; ++ct)
        cost += (max - cit[ct]);
    printf("%d", cost);
    return 0;
}