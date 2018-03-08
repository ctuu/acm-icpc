#include <stdio.h>
int main(void)
{
    int i;
    int x = 0;
    int k;
    _Bool oj = 0;
    int co[100] = {0};
    char ct;
    while (~scanf("%d", &i))
    {
        x = 0;
        oj = 0;
        while (getchar() != '\n')
            continue;
        int co[100] = {0};
        for (; i > 0; i--)
        {
            ct = getchar();
            if (ct == 'B' && oj == 0)
            {
                x++;
                co[x] += 1;
                oj = 1;
            }
            else if (ct == 'B' && oj == 1)
            {
                co[x] += 1;
            }
            else if (ct == 'W' && oj == 1)
                oj = 0;
        }
        printf("%d\n", x);
        for (k = 1; k <= x; k++)
        {
            printf("%d ", co[k]);
            co[k] = 0;
        }
        printf("\n");
    }
    return 0;
}