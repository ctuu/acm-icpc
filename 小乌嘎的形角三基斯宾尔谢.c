#include <stdbool.h>
#include <stdio.h>
#define N 2100
#define M 10
void draw(int x, int y, int level);
char xrbs[N][N];
int xn[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int main(void)
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            xrbs[i][j] = ' ';
    draw(0, 0, M);
    int n;
    bool fl = 0;
    while (~scanf("%d", &n) && n != 0)
    {
        if (fl)
            printf("\n");
        fl = 1;
        for (int i = 0; i < xn[n + 1] - 1; ++i)
            printf("%c", xrbs[0][i]);
        printf("\n");
        int limit = xn[n + 1];
        for (int i = 1; i <= xn[n]; ++i)
        {
            for (int j = 0; j < limit; ++j)
                printf("%c", xrbs[i][j]);
            printf("\n");
            --limit;
        }
    }
    return 0;
}
void draw(int x, int y, int level)
{
    if (level > 1)
    {
        draw(x, y, level - 1);
        draw(x, y + xn[level], level - 1);
        draw(x + xn[level - 1], y + xn[level - 1], level - 1);
    }
    xrbs[x][y + 1] = xrbs[x][y + 2] = '_';
    xrbs[x + 1][y] = xrbs[x + 2][y + 1] = '\\';
    xrbs[x + 1][y + 3] = xrbs[x + 2][y + 2] = '/';
    return;
}