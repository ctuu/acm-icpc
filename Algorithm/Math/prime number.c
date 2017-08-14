#include <stdio.h>
void pn(long long a);
int main(void)
{
    long long n, i;
    for (i = 1; 1 < 10000; i++)
    {
        pn(i);
    }
    return 0;
}

void pn(long long a)
{
    long long n;
    if (a == 1)
        return;
    for (n = 2; n * n <= a; n++)
    {
        if (a % n == 0)
            return;
    }
    printf("%lld,", a);
}