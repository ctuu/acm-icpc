#include <stdio.h>
void dfs(long long num);
long long sum;

int main(void)
{
    long long t, num;
    scanf("%lld", &t);
    for (; t > 0; t--)
    {
        sum = 0;
        scanf("%lld", &num);
        dfs(num);
        printf((t != 1) ? "%lld\n" : "%lld", sum);
    }
    return 0;
}
void dfs(long long num)
{
    if (num <= 1)
        return;
    long long base, ct;
    for (ct = 0, base = 2; base <= num; base *= 2, ct++)
        ;
    if (num - base / 2 > 0)
        dfs(num - base / 2);
    for (num = 1; ct > 0; num *= 2, ct--)
        ;
    sum += num - 1;
}