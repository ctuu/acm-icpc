#include <stdio.h>
int main(void)
{
    int a, b, c, t;
    scanf("%d%d%d", &a, &b, &c);
    t = (a > b) ? a : b;
    t = (t > c) ? t : c;
    a = (a < b) ? a : b;
    a = (a < c) ? a : c;
    printf("%d", t - a);
    return 0;
}