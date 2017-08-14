#include <cstdio>
#include <iostream>
#include<algorithm>
using namespace std;
int num[200000];

int main(void)
{
    int n, a, b, snum, i, temp, o;
    int t, c, d, k, q;
    double sum = 0;
    double su = 0;
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        sum = 0;
        su = 0;
        snum = n;
        for (i = 0; i < snum; i++)
            scanf("%d", &num[i]);
        sort(num,num + n);
        c = a;
        d = b;
        if (a > b)
        {
            c = b;
            d = a;
            k = a;
            a = b;
            b = k;
        }
        for (q = snum - 1; c > 0; q--, c--)
            sum += num[q];
        sum /= a;
        for (; d > 0; q--, d--)
            su += num[q];
        su /= b;
        printf("%.8lf\n", sum + su);
    }
    return 0;
}