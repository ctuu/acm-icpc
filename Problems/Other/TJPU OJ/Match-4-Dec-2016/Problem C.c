#include <stdio.h>
int main(void)
{
    int T, k;
    while (~scanf("%d", &k))
    {
        if (k % 2 == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}