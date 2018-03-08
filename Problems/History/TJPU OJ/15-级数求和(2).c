#include <stdio.h>
int main(void)
{
    int k;
    long double a, b;
    long double num;
    scanf("%d", &k);
    if (k > 1000000)
        printf("1.64493");
    else 
    {
        for (a = 1, num = 0; a < k + 1; a++)
        num += 1 / a / a;
    printf("%.5Lf", num);
    }
    return 0;
}