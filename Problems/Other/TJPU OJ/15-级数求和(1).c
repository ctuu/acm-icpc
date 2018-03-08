#include <stdio.h>
int main(void)
{
    int k;
    long double a;
    long double num;
    scanf("%d", &k);
    for (a = 1, num = 0; num <= k; a++)
        num += 1 / a;
    printf("%.Lf", a - 1);
    return 0;
}