#include <stdio.h>
long long GCD(long long a, long long b);
long long LCM(long long a, long long b);

int main(void)
{
    long long num, ct, sum, su;
    while (~scanf("%lld", &num))
    {
        for (su = 1, sum = 0, ct = 2; ct <= num; ct++)
        {
            sum = LCM(su, ct);
            printf("%lld: %lld\n", ct, sum);
            su = sum;
        }
        printf("%lld\n", sum % 4294967296);
    }
    return 0;
}
long long GCD(long long a, long long b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}

long long LCM(long long a, long long b)
{
    return a * b / GCD(a, b);
}