#include <bits/stdc++.h>
const long long MOD = 1e8 + 7;
using namespace std;
long long pow(long long a, long long b)
{
    long long t = 1;
    long long ba = a % MOD;
    while (b)
    {
        if (b & 1)
        {
            t *= ba;
            t %= MOD;
            ba *= ba;
            ba %= MOD;
            b >>= 1;
        }
    }
    return t;
}
int main()
{
    long long a;
    while (cin >> a)
    {
        a = (long long) (pow(2, a) - 1)  % MOD;
        cout << a << endl;
    }
    return 0;
}