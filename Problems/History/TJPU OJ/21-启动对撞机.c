#include <stdio.h>
int main(void)
{
    int ct, co;
    int min = 600000000;
    int num[200000];
    char dir[200000];
    while (~scanf("%d", &co))
    {
        min = 600000000;
        while (getchar() != '\n')
            continue;
        for (ct = 0; ct < co; ct++)
            dir[ct] = getchar();
        for (ct = 0; ct < co; ct++)
                scanf("%d", &num[ct]);
        for (ct = 0; ct < co - 1; ct++)
            if (dir[ct] == 'R' && dir[ct + 1] == 'L')
                min = ((num[ct + 1] - num[ct]) / 2 < min) ? (num[ct + 1] - num[ct]) / 2 : min;
        if (min == 600000000)
            printf("-1");
        else
            printf("%d\n", min);
    }
    return 0;
}