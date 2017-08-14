#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mirp[1005];
int a[10000005] = {0};
char rev[1000];
void makepnum()
{
    int i, j;
    for (i = 2; i <= 500000; i++)
        for (j = 2 * i; j <= 1000000; j += i)
        {
            a[j] = 1;
        }
}
void makeemirp()
{
    int i, j, len, num, k = 1;
    char t;
    for (i = 13; k <= 1005; i++)
    {
        if (a[i] == 0)
        {
            sprintf(rev, "%d", i);
            //    puts(rev);
            len = strlen(rev) - 1;
            for (j = 0; j <= len; j++, len--)
            {
                t = rev[j];
                rev[j] = rev[len];
                rev[len] = t;
            }
            //puts(rev);
            num = atoi(rev);
            // printf("%d\n", num);
            if (a[num] == 0 && num != i)
            {
                mirp[k++] = i;
            }
        }
    }
}
int main()
{
    makepnum();
    makeemirp();
    int i, n, num;
    //for (i = 0; i < 1005; i++)
    //    printf("%d\n", mirp[i]);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &num);
        printf("%d\n", mirp[num]);
    }
}