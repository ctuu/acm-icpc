#include <stdio.h>
int main(void)
{
    int map[200][200];
    int x, y, mx, my, total;
    scanf("%d%d", &mx, &my);
    total = mx * my;
    for (x = 0; x < mx; ++x)
        for (y = 0; y < my; ++y)
            scanf("%d", &map[x][y]);
    x = y = 0;
    while (total)
    {
        while (x < mx && map[x][y] != -1 && total--)
        {
            printf("%d", map[x][y]);
            if (total)
                printf(" ");
            map[x][y] = -1;
            ++x;
        }
        --x;
        ++y;
        while (y < my && map[x][y] != -1 && total--)
        {
            printf("%d", map[x][y]);
            if (total)
                printf(" ");
            map[x][y] = -1;
            ++y;
        }
        --y;
        --x;
        while (x > -1 && map[x][y] != -1 && total--)
        {
            printf("%d", map[x][y]);
            if (total)
                printf(" ");
            map[x][y] = -1;
            --x;
        }
        ++x;
        --y;
        while (y > -1 && map[x][y] != -1 && total--)
        {
            printf("%d", map[x][y]);
            if (total)
                printf(" ");
            map[x][y] = -1;
            --y;
        }
        ++y;
        ++x;
    }
    return 0;
}