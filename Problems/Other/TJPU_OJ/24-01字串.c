#include <stdio.h>

int main(void)
{
    int num, a, b;
    char ch[5] = {0};
    for (num = 0; num < 32; num++)
    {
        char ch[5] = {0};
        a = num;
        for (b = 4; b >= 0; b--, a >>= 1)
            ch[b] = (01 & a) + '0';
        puts(ch);
    }
    return 0;
}