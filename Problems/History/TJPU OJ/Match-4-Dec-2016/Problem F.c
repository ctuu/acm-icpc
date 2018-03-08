#include <stdio.h>
int main(void)
{
    int T, t;
    int n, m;
    int a, b, ct;
    int num[30][30] = {0};
    for (t = 1, scanf("%d", &T); t <= T; t++)
    {

        int num[30][30] = {0};
        scanf("%d%d", &n, &m);
        for (a = 0; a < n; a++)
            for (b = 0; b < m; b++)
                scanf("%d", &num[a][b]);
        printf("Case #%d: ", t);

        for (b = 0; b < m - 1; b++)
            for (ct = b + 1; ct < m; ct++)
                if (num[0][b] == num[0][ct])
                    goto ac;

        for (a = 0; a < n - 1; a++)
            for (ct = a + 1; ct < n; ct++)
                if (num[a][0] == num[ct][0])
                    goto ac;

        for (b = 0; b < m - 1; b++)
            for (ct = b + 1; ct < m; ct++)
                if (num[n - 1][b] == num[n - 1][ct])
                    goto ac;

        for (a = 0; a < n - 1; a++)
            for (ct = a + 1; ct < n; ct++)
                if (num[a][m - 1] == num[ct][m - 1])
                    goto ac;

        for (a = 1; a < n - 1; a++)
            for (b = 1; b < m - 1; b++)
            {
                if (num[a][b] == num[a][b + 1] || num[a][b] == num[a + 1][b])
                    goto ac;
            }

        printf("No\n");
        continue;
    ac:
        printf("Yes\n");
    }
    return 0;
}