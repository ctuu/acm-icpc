#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
LL fac[2005] = {0};
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= 2000; i++)
        fac[i] = fac[i - 1] * i % mod;
}

LL q_pow(LL x, LL n)
{
    LL ans = 1;
    x %= mod;
    while (n)
    {
        if (n & 1)
            ans = (ans * x) % mod;
        n >>= 1;
        x = (x * x) % mod;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if (m > n)
        return 0;
    return fac[n] * q_pow(fac[m] * fac[n - m] % mod, mod - 2) % mod;
}

LL C(LL n, LL m)
{
    if (m > n)
        return 0;
    LL te = 1;
    for (int i = n - m; i > 0; ++i)
    te *= 
    return fac[n] * q_pow(fac[m] * fac[n - m] % mod, mod - 2) % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    while (T--)
    {
        LL n, m;
        cin >> n >> m;
        if (m < n)
        {
            LL sum = (q_pow(m - 1, n) * m + mod) % mod;
            for (int k = 2; k <= m; k++)
            {
                sum += 2 * (C(m, k) * q_pow(m - k, n) % mod);
            }
            cout << sum << endl;
        }
        else
        {
            LL sum = (q_pow(m - 1, n) * m + mod) % mod;
            for (int k = 2; k <= n; k++)
            {
                sum += 2 * (C(m, k) * q_pow(m - k, n) % mod);
            }
            cout << sum << endl;
        }
    }
    return 0;
}