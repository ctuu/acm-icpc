#include <stdio.h>
int main(void)
{
    int t;
    long long n;
    long long sum;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        // sum = 1;
        for(sum = 1; n > 0; --n)
        sum *= n;
        printf("%lld\n", sum);
    }
    return 0;
}