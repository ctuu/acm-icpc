#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t, ct;
    cin >> n >> t;
    vector<int> cl, va, cr, vc, cr2;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        cl.push_back(tmp);
    }
    for (int i = 0; i < n; ++i)
    {
        int r = 1;
        cin >> ct;
        while (ct >= r)
        {
            va.push_back(r * cl[i]);
            cr.push_back(r);
            ct -= r;
            r <<= 1;
        }
        while (ct)
        {
            if (ct >= r)
            {
                va.push_back(r * cl[i]);
                cr.push_back(r);
                ct -= r;
            }
            r >>= 1;
        }
        r = 1;
        while (r * cl[i] < 11002)
        {
            vc.push_back(r * cl[i]);
            cr2.push_back(r);
            r <<= 1;
        }
    }
    int dp[11002], kdp[11002];
    for (int i = 0; i < 11002; ++i)
    {
        dp[i] = INF;
        kdp[i] = INF;
    }
    dp[0] = 0;
    kdp[0] = 0;
    ct = va.size();
    for (int i = 0; i < ct; ++i)
        for (int j = 11000; j >= va[i]; --j)
            dp[j] = min(dp[j], dp[j - va[i]] + cr[i]);
    ct = vc.size();
    for (int i = 0; i < ct; ++i)
        for (int j = 11000; j >= vc[i]; --j)
            kdp[j] = min(kdp[j], kdp[j - vc[i]] + cr2[i]);
    int ans = INF;
    for (int i = t; i <= 11000; ++i)
        ans = min(ans, dp[i] + kdp[i - t]);
    if (ans == INF)
        cout << "-1";
    else
        cout << ans;
    return 0;
}