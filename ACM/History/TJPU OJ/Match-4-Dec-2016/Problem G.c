#include <stdio.h>
int main(void)
{
    int T, t;
    long long a, b;
    for (t = 0, scanf("%d", &T); T > t;)
    {
        scanf("%lld%lld", &a, &b);
        printf("Case #%d:\n", ++t);
        if (a == b)
            printf("1\n%lld %lld\n", a, b);
        else
            printf("2\n%lld %lld\n%lld %lld\n", a, b, b, a);
    }
    return 0;
}