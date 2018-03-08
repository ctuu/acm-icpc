#include <stdio.h>

int c;
long long num[91];

char judge(int n, long long m);

int main(void)
{
    int T, n;
    long long m;
    for (num[0] = 0, num[1] = 1, num[2] = 2, c = 3; c < 91; c++)
    num[c] = num[c - 1] + num[c - 2];

    for (scanf("%d", &T); T > 0; T--)
    {
        scanf("%d%lld", &n, &m);
        printf("%c\n", judge(n, m));
    }
    return 0;
}

char judge(int n, long long m)
{
    if (m == 1)
            return 'a';
    if (m == 2)
            return 'b';
    if (m > num[n - 1])
        m -= num[n - 1];
    judge(n - 1, m);
}