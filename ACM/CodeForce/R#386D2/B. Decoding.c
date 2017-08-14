#include <stdio.h>
int main(void)
{
    int leng, be, en, temp;
    char encode[2001];
    char decode[2001];
    scanf("%d", &leng);
    scanf("%s", encode);
    be = 0;
    en = leng - 1;
    temp = leng;
    for (leng--; leng > -1; leng--, be++, en--)
    {
        decode[en] = encode[leng];
        if (leng > 0)
            decode[be] = encode[--leng];
    }
    for (be = 0; be < temp; be++)
        printf("%c", decode[be]);
    return 0;
}