#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main(void)
{
    double rad[10];
    int t;
    double n, d, sum;
    while (~scanf("%lf%lf", &n, &d))
    {
        for (sum = 0, t = 0; t < n; t++)
        {
            scanf("%lf", &rad[t]);
            sum += d * d * sin(rad[t] * PI / 180) / 2;
        }
        printf("%.3f\n", sum);
    }
    return 0;
}
