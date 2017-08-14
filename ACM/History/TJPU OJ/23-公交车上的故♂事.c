#include <stdio.h>
int main(void)
{
    char seat[1000][6];
    int ln, te, tm;
    _Bool oj, oji;
    while (~scanf("%d", &ln))
    {
        while (getchar() != '\n')
            continue;
        for (te = 0; te < ln; te++)
        {
            for (tm = 0; tm < 6; tm++)
            {
                seat[te][tm] = getchar();
                if (seat[te][tm] == 'O' && oj == 0 && oji == 0)
                    oj = 1;
                else if (seat[te][tm] == 'O' && oj == 1 && oji == 0)
                {
                    seat[te][tm] = '+';
                    seat[te][tm - 1] = '+';
                    oji = 1;
                }
                else if ((seat[te][tm] == 'X' || seat[te][tm] == '|') && oj == 1)
                    oj = 0;
            }
            oj = 0;
        }
        if (oji == 0)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for (te = 0; te < ln * 6; te++)
                printf("%c", seat[0][te]);
        }
        oji = 0;
    }
    return 0;
}