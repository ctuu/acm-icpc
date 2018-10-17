#include <stdio.h>
#define ROW 30
#define COL 30

int trea[ROW][COL] = {0};

int a, b;
_Bool flag = 0;
int sum = 0;
int dfs(int x, int y);
int check(void);

int main(void)
{
    int x, y, xt, yt;
    while (~scanf("%d%d", &x, &y))
    {
        for (xt = 0; xt < x; xt++)
            for (yt = 0; yt < y; yt++)
                scanf("%d", &trea[xt][yt]);
        printf("%d\n", check());
    }
    return 0;
}

int check(void)
{
    int max = 0;
    for (a = 0; a < ROW; a++)
        for (b = 0; b < COL; b++)
        {
            flag = 0;
            dfs(a, b);
            max = (max > sum) ? max : sum;
            sum = 0;
        }
    return max;
}

int dfs(int x, int y)
{
    if (x < ROW && y < COL)
    {
        if (trea[x][y])
        {
            trea[x][y] = 0;
            sum += 1;
            if (flag == 0)
            {
                a = x;
                b = y;
                flag = 1;
            }
            if (x > 0)
            {
                if (trea[x - 1][y])
                    dfs(x - 1, y);
            }
            if (trea[x + 1][y])
                dfs(x + 1, y);
            if (y > 0)
            {
                if (trea[x][y - 1])
                    dfs(x, y - 1);
            }
            if (trea[x][y + 1])
                dfs(x, y + 1);
        }
    }
}