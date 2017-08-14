#include <stdio.h>
void dfs(int n, int a, int b, int c);
int main(void)
{
    int n;
    scanf("%d", &n);
    dfs(n, 'a', 'b', 'c');
}

void dfs(int n, int a, int b, int c)
{
    if (n >= 1)
    {
        dfs(n - 1, a, c, b);
        printf("%d: %c to %c\n", n, a, c);
        dfs(n - 1, b, a, c);
    }
}