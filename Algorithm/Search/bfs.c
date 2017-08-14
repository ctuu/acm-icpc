#include <stdio.h>
#include <stdlib.h>
#define MX 9
#define MY 9

int map[MX][MY] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
};

typedef struct hu
{
    int x;
    int y;
    int co;
    int dig;
    struct hu *next;
} BFS;
int min = -1;
int main(void)
{
    int a, b, c, d, t;
    scanf("%d", &t);
    while (t--)
    {
        min = -1;
        int map[MX][MY] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 1, 0, 0, 1, 0, 1},
            {1, 0, 0, 1, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 1, 0, 0, 1},
            {1, 1, 0, 1, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
        };
        scanf("%d%d%d%d", &a, &b, &c, &d);
        BFS *temp;
        BFS *te;
        BFS *end;
        BFS *NN;
        temp = (BFS *)malloc(sizeof(BFS));
        temp->x = a;
        temp->y = b;
        temp->co = 0;
        temp->dig = 0;
        temp->next = NULL;
        end = temp->next;
        for (; temp != NULL; te = temp, temp = temp->next, free(te))
        {
            NN = temp;
            //map[temp->x][temp->y] = 1;
            //printf("HELLO %d, %d\n",temp->x, temp->y);
            if (temp->x == c && temp->y == d)
            {
                if (min == -1)
                    min = temp->co;
                else
                    min = (min < temp->co) ? min : temp->co;
                break;
            }
            if (temp->dig != 2 && temp->y > 0 && map[temp->x][temp->y - 1] != 1)
            {
                //map[temp->x][temp->y] = 1;
                // printf("1\n");
                end = (BFS *)malloc(sizeof(BFS));
                end->x = temp->x;
                end->y = temp->y - 1;
                end->co = temp->co + 1;
                end->dig = 1;
                end->next = NULL;
                while (NN->next != NULL)
                    NN = NN->next;
                NN->next = end;
                end = end->next;
            }
            if (temp->dig != 1 && temp->y < MX - 1 && map[temp->x][temp->y + 1] != 1)
            {
                //map[temp->x][temp->y] = 1;
                // printf("2\n");
                end = (BFS *)malloc(sizeof(BFS));

                end->x = temp->x;
                end->y = temp->y + 1;
                end->co = temp->co + 1;
                end->dig = 2;
                end->next = NULL;
                while (NN->next != NULL)
                    NN = NN->next;
                NN->next = end;
                end = end->next;
            }
            if (temp->dig != 4 && temp->x > 0 && map[temp->x - 1][temp->y] != 1)
            {
                //map[temp->x][temp->y] = 1;
                // printf("3\n");
                end = (BFS *)malloc(sizeof(BFS));
                end->x = temp->x - 1;
                end->y = temp->y;
                end->co = temp->co + 1;
                end->dig = 3;
                end->next = NULL;
                while (NN->next != NULL)
                    NN = NN->next;
                NN->next = end;
                end = end->next;
            }
            if (temp->dig != 3 && temp->x < MX && map[temp->x + 1][temp->y] != 1)
            {
                //map[temp->x][temp->y] = 1;
                //   printf("4\n");
                end = (BFS *)malloc(sizeof(BFS));
                end->x = temp->x + 1;
                end->y = temp->y;
                end->co = temp->co + 1;
                end->dig = 4;
                end->next = NULL;
                while (NN->next != NULL)
                    NN = NN->next;
                NN->next = end;
                end = end->next;
            }
        }
        printf("%d\n", min);
    }
    return 0;
}