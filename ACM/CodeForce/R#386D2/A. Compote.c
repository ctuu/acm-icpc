#include <stdio.h>
int main(void)
{
    int a, b, c, n;
    scanf("%d%d%d", &a, &b, &c);
    a /= 1;
    b /= 2;
    c /= 4;
    for (n = 0; a > 0 && b > 0 && c > 0; a--, b--, c--)
            n += 7;
    printf("%d", n);
    return 0;
}