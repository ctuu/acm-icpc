#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const long long mod = 1e9 + 7;
vector<LL> fac, finv;
void init_fav_finv(int n)
{
    fac.resize(n);
    finv.resize(n);
    fac[0] = 1;
    for (int i = 1; i < n; i++)
        fac[i] = fac[i - 1] * i % mod;
    finv[1] = 1;
    for (int i = 2; i < n; i++)
        finv[i] = finv[mod % i] * (mod - mod / i) % mod;
    finv[0] = 1;
    for (int i = 1; i < n; i++)
        finv[i] = finv[i - 1] * finv[i] % mod;
}
LL Comb(LL n, LL m)
{
    return fac[n] * finv[m] % mod * finv[n - m] % mod;
}
LL poww(LL x, LL n)
{
    LL ans = 1, base = x;
    while (n != 0)
    {
        if (1 & n)
            ans = ans * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init_fav_finv(1000003);
    int T, n, m, k;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> m >> k;
        LL ans = 0;
        for (int i = 0; i < k - 1; ++i)
        {
            LL tmp = (Comb(k, i) * poww(k - i - 1, n - 1) % mod) * (k - i) % mod;
            if (i & 1)
                ans = (ans - tmp + mod) % mod;
            else
                ans = (ans + tmp) % mod;
        }
        LL cm = 1;
        for (int i = 0; i < k; ++i)
            cm = cm * (m - i) % mod;
        cm = cm * finv[k] % mod;
        ans = ans * cm % mod;
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}