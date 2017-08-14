#include <stdio.h>
int main(void)
{
    long long n;
    long long sum;
    while (~scanf("%lld", &n))
    {
        for (sum = 1; n > 0; n--)
            sum *= n;
        printf("%lld\n", sum + 11);
    }
    return 0;
}