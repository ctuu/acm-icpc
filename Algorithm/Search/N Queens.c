#include <stdio.h>
#define NUM 4

int queen[NUM][NUM] = {0};
_Bool pin[3][2 * NUM];
int co = 0;

void find(int x, int y);
int main(void)
{
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
            if (pin[0][y] == 0 && pin[1][x + y] == 0 && pin[2][NUM - 1 + y - x] == 0)
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
        co++;
        printf("No.%d\n",co);
        for (a = 0; a < NUM; a++)
        {
            for (b = 0; b < NUM; b++)
                printf("%d ", queen[a][b]);
            printf("\n");
        }
        
    }
}