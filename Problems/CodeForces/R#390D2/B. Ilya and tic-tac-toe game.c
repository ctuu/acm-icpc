#include <stdio.h>
int main(void)
{
    char sam[5] = {'x', 'x', '.', 'x', 'x'};
    char ch[4][4];
    int x, y, t;
    _Bool flag = 0;
    for (x = 0; x < 4; ++x)
        for (y = 0; y < 4; ++y)
            scanf("%1s", &ch[x][y]);
    for (x = 0; x < 4; x++)
        for (y = 0; y < 2; y++)
            for (t = 0; t < 3; t++)
                if (ch[x][y] == sam[t] && ch[x][y + 1] == sam[t + 1] && ch[x][y + 2] == sam[t + 2])
                    flag = 1;

    for (y = 0; y < 4; y++)
        for (x = 0; x <= 1; x++)
            for (t = 0; t < 3; t++)
                if (ch[x][y] == sam[t] && ch[x + 1][y] == sam[t + 1] && ch[x + 2][y] == sam[t + 2])
                    flag = 1;

    for (t = 0; t < 3; t++)
        if (ch[0][0] == sam[t] && ch[1][1] == sam[t + 1] && ch[2][2] == sam[t + 2])
            flag = 1;
    for (t = 0; t < 3; t++)
        if (ch[1][1] == sam[t] && ch[2][2] == sam[t + 1] && ch[3][3] == sam[t + 2])
            flag = 1;
    for (t = 0; t < 3; t++)
        if (ch[0][1] == sam[t] && ch[1][2] == sam[t + 1] && ch[2][3] == sam[t + 2])
            flag = 1;
    for (t = 0; t < 3; t++)
        if (ch[1][0] == sam[t] && ch[2][1] == sam[t + 1] && ch[3][2] == sam[t + 2])
            flag = 1;

    for (t = 0; t < 3; t++)
        if (ch[0][3] == sam[t] && ch[1][2] == sam[t + 1] && ch[2][1] == sam[t + 2])
            flag = 1;
    for (t = 0; t < 3; t++)
        if (ch[1][2] == sam[t] && ch[2][1] == sam[t + 1] && ch[3][0] == sam[t + 2])
            flag = 1;
    for (t = 0; t < 3; t++)
        if (ch[0][2] == sam[t] && ch[1][1] == sam[t + 1] && ch[2][0] == sam[t + 2])
            flag = 1;
    for (t = 0; t < 3; t++)
        if (ch[1][3] == sam[t] && ch[2][2] == sam[t + 1] && ch[3][1] == sam[t + 2])
            flag = 1;

    if (flag == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}