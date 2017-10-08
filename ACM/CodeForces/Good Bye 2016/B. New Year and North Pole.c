#include <stdio.h>
int main(void)
{
    int NS = 0;
    int n, temp, kq;
    char ch[10];
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%s", &temp, ch);
        if (NS > 0)
            kq = NS;
        else
            kq = -NS;
        if (kq > 20000)
        if (ch[0] == 'N' && kq % 20000 == 0 && kq % 40000 == 0)
        {
            NS = 1;
            break;
        }
        if (ch[0] == 'S' && kq != 0 && kq % 20000 == 0 && kq % 40000 != 0)
        {
            NS = 1;
            break;
        }
        else if (ch[0] == 'N')
            NS += temp;
        else if (ch[0] == 'S')
            NS -= temp;
        else if (ch[0] == 'W' && NS % 20000 == 0)
        {
            NS = 1;
            break;
        }
        else if (ch[0] == 'E' && NS % 20000 == 0)
        {
            NS = 1;
            break;
        }
    }
    if (NS > 0)
        kq = NS;
    else
        kq = -NS;
    if (kq == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
