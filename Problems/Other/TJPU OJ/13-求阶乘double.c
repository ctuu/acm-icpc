#include <stdio.h>
int main(void)
{
    double n;
    double sum;
    while (~scanf("%Lf", &n))
    {
        for (sum = 1; n > 0; n--)
            sum *= n;
        printf("%.Lf\n", sum + 11);
    }
    return 0;
}