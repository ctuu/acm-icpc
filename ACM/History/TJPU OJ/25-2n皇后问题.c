#include <stdio.h>
//#define NUM 10
int NUM;
int queen[8][8] = {0};
int qute[8][8] = {0};
int qtemp[8][8] = {0};
int queend[8][8] = {0};
_Bool pin[3][2 * 8];
_Bool pind[3][2 * 8];

int co = 0;

void find(int x, int y);
void findd(int x, int y);
int main(void)
{
    int temp, x, y;
    scanf("%d", &NUM);
    for (x = 0; x < NUM; x++)
        for (y = 0; y < NUM; y++)
        {
            scanf("%d", &temp);
            qute[x][y] = 1 ^ temp;
        }
    find(0, 0);
    printf("%d", co);
    return 0;
}

void find(int x, int y)
{
    int a, b;
    if (x < NUM)
    {
        for (y = 0; y < NUM; y++, a = 0)
        {
            if (pin[0][y] == 0 && pin[1][x + y] == 0 && pin[2][NUM - 1 + y - x] == 0 && qute[x][y] == 0)
            {
                pin[0][y] = pin[1][x + y] = pin[2][NUM - 1 + y - x] = queen[x][y] = a = 1;
                find(x + 1, 0);
                pin[0][y] = pin[1][x + y] = pin[2][NUM - 1 + y - x] = queen[x][y] = 0;
            }
        }
        if (a == 1)
            find(x + 1, 0);
    }
    else
    {
        //co++;
        for (a = 0; a < NUM; a++)
        {
            for (b = 0; b < NUM; b++)
            {
                qtemp[a][b] = queen[a][b] | qute[a][b];
            }
        }
        findd(0, 0);
        /*        printf("No.%d\n", co);
        for (a = 0; a < NUM; a++)
        {
            for (b = 0; b < NUM; b++)
                printf("%2d ", queen[a][b]);
            printf("\n");
        }*/
    }
}

void findd(int x, int y)
{
    int a, b;
    if (x < NUM)
    {
        for (y = 0; y < NUM; y++, a = 0)
        {
            if (pind[0][y] == 0 && pind[1][x + y] == 0 && pind[2][NUM - 1 + y - x] == 0 && qtemp[x][y] == 0)
            {
                pind[0][y] = pind[1][x + y] = pind[2][NUM - 1 + y - x] = queend[x][y] = a = 1;
                findd(x + 1, 0);
                pind[0][y] = pind[1][x + y] = pind[2][NUM - 1 + y - x] = queend[x][y] = 0;
            }
        }
        if (a == 1)
            findd(x + 1, 0);
    }
    else
    {
        co++;
/*        printf("No.%d\n", co);
        for (a = 0; a < NUM; a++)
        {
            for (b = 0; b < NUM; b++)
                printf("%d ", queend[a][b]);
            printf("\n");
        }*/
    }
}