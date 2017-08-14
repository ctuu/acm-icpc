#include <bits/stdc++.h>
#define N 105
#define INF 0x3f3f3f3f
#define M 100005
#define AI 100000
#define CI 1000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    array<int, N> a;
    array<int, N> c;
    while (cin >> n >> m && n && m)
    {
        vector<int> va;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> c[i];

        for (int i = 0; i < n; ++i)
        {
            int r = 1;
            while (c[i] >= r)
            {
                va.push_back(a[i] * r);
                c[i] -= r;
                r <<= 1;
            }
            while (c[i])
            {
                while (c[i] < r)
                    r >>= 1;
                va.push_back(a[i] * r);
                c[i] -= r;
            }
        }
        // for (auto i: va)
        // cout << i << endl;
        array<int, M> dp;
        dp.fill(-INF);
        dp[0] = 0;
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j = m; j >= va[i]; --j)
                dp[j] = max(dp[j], dp[j - va[i]] + va[i]);
        int ans = 0;
        for (int i = 0; i <= m; ++i)
            if (dp[i] > 0)
                ++ans;
        cout << ans << endl;
    }
    return 0;
}