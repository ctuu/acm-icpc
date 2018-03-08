#include <stdio.h>
int main(void)
{
    long long n, a, b, c;
    int i;
    long long T, min;
    for (scanf("%lld", &T); T > 0; T--)
    {
        scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
        if (n == 0)
            i = 4;
        else if (n < 4)
            i = 4 - n;
        else
            i = 4 - n % 4;

        switch (i)
        {
        case 4:
            min = 0;
            break;
        case 1:
            min = a;
            break;
        case 2:
            min = 2 * a;
            min = (min < b) ? min : b;
            break;
        case 3:
            min = 3 * a;
            min = (min < (a + b)) ? min : (a + b);
            min = (min < c) ? min : c;
            break;
        case 0:
            min = 4 * a;
            min = (min < (2 * b)) ? min : (2 * b);
            min = (min < (b + 2 * a)) ? min : (b + 2 * a);
            min = (min < (a + c)) ? min : (a + c);
            break;
        }
        printf("%lld\n", min);
    }
    return 0;
}