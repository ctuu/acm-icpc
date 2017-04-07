#include <stdio.h>

#define MAX 0x3fffffff
int map[105][105], dis[105];
bool use[105];
int n, m;

void dijk(int start)
{
    int min, rj, i, j;
    for (j = 1; j <= n; j++)
    {
        dis[j] = map[1][j];
        use[j] = 0;
    }
    use[1] = 1;
    for (i = 1; i < n; i++)
    {
        min = MAX;
        for (j = 1; j <= n; j++)
        {
            if (use[j] == 1)
                continue;
            if (dis[j] < min)
            {
                min = dis[j];
                rj = j;
            }
        }

        use[rj] = 1;
        for (j = 1; j <= n; j++)
        {
            if (use[j] == 1)
                continue;
            if (dis[j] > dis[rj] + map[rj][j])
                dis[j] = dis[rj] + map[rj][j];
        }
    }
}

int main()
{
    int i, j, a, b, temp;
    while (scanf("%d%d", &n, &m), n || m)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                map[i][j] = MAX;
            }
        }
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &a, &b);
            scanf("%d", &temp);
            if (temp < map[a][b])
            {
                map[b][a] = temp;
                map[a][b] = temp;
            }
        }

        dijk(1);
        printf("%d\n", dis[n]);
    }
}