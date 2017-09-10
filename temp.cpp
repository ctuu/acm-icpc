#include <bits/stdc++.h>
using namespace std;
long long x, y;
int judge(long long i, long long n)
{
    if ((long long)sqrt((i * i - 1) / 2) * (long long)sqrt((i * i - 1) / 2) == (i * i - 1) / 2 && i * i != n) //i*i!=n是为了要保证x不能小于n
    {
        x = i * i - 1;
        y = i * i;
        return 1;
    }
    else if ((long long)sqrt((i * i + 1) / 2) * (long long)sqrt((i * i + 1) / 2) == (i * i + 1) / 2)
    {
        x = i * i;
        y = i * i + 1;
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    long long n = 1, i;
    while (n <= 1e16)
    {
        i = (long long)ceil(sqrt(n)); //不能向下取整，要保证答案是大于等于n的
        if (i % 2 == 0)               //我枚举的是奇数
        {
            i++;
        }
        while (judge(i, n) == 0)
        {
            i = i + 2;
        }
        printf("%lld\n", x);
        n = y;
    }
}