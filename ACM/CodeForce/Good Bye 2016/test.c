#include <bits/stdc++.h>
#define d 20000
char direction[10];
int main()
{
    int nb, dx, n, tmp, i, flag;
    while (~scanf("%d", &n))
    {
        getchar();
        flag = nb = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &tmp);
            getchar();
            scanf("%s", direction);
            getchar();
            if (strcmp(direction, "South") == 0)
            {
                if (nb == d)
                    flag = 1;
                else if (nb >= 20000)
                {
                    nb -= tmp;
                }
                else if (nb < 20000)
                {
                    nb += tmp;
                }
            }
            else if (strcmp(direction, "North") == 0 && nb != 0)
            {
                if (nb == 0)
                    flag = 1;
                else if (nb >= 20000 && nb - temp >=200000)
                {
                    nb -= tmp;
                }
                else if (nb < 20000)
                {
                    nb -= tmp;
                }
            }
            else if (strcmp(direction, "East") == 0)
            {
                if ((nb == 0 || nb == d))
                {
                    flag = 1;
                }
            }
            else if (strcmp(direction, "West") == 0)
            {
                if ((nb == 0 || nb == d))
                {
                    flag = 1;
                }
            }
            if (nb < 0 || nb > 40000)
                flag = 1;
        }
        nb %= 40000;
        if (flag == 1 || nb != 0)
            printf("NO\n");
        if (nb == 0 && flag != 1)
            printf("YES\n");
    }
}