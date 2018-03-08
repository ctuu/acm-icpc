#include <stdio.h>
int main(void)
{
    int n, ct, x1, y1, x2, y2;
    int X, Y, X0, Y0, sum;
    double a, b;
    ct = 0;
    sum = 0;
    scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
    if ((x2 - x1) != 0)
        a = (y2 - y1) / (x2 - x1);
    else a = 0;
    while (n--)
    {
        scanf("%d%d%d%d", &X, &Y, &X0, &Y0);
        if ((X0 - X) != 0)
        b = (Y0 - Y) / (X0 - X);
        else b = 0;
        for (ct = 0; ct <= x2; ct++)
            if (y1 + ct * a == Y + ct * b)
                sum++;
    }
    printf("%d", sum);
    return 0;
}