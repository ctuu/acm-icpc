#include <stdio.h>
int main(void)
{
    int a, x, b;
    scanf("%d%d%d", &a, &x, &b);
    if (a == x)
        printf("YES");
    else if (b != 0 && (x - a - b) / b >= 0 && (x - a - b) % b == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}