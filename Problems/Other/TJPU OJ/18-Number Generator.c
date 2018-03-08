#include <stdio.h>

void dfs(int n, int *t);
int main(void)
{
    int a;
    int co = 0;
    while (~scanf("%d", &a))
    {
        dfs(a, &co);
        printf("%d\n", co + 1);
        co = 0;
    }
    return 0;
}

void dfs(int n, int *t)
{
    int i;
    for (i = 1; i <= n / 2; i++)
    {
        *t += 1;
        dfs(i, t);
    }
}