#include <bits/stdc++.h>
#define N 1005
#define M 1005
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, N> veg;
    veg.fill(0);
    int n, m;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
            cin >> veg[i];
        sort(veg.begin(), veg.begin() + n);
        cin >> m;
        if (m < 5)
        {
            cout << m << endl;
            continue;
        }
        array<int, M> dp;
        dp.fill(0);
        for (int i = 0; i < n - 1; ++i)
            for (int j = n - 1; j > -1; --j)
                dp[j] = max(dp[j], (dp[j - 1] + veg[i] <= m - 5) ? dp[j - 1] + veg[i] : dp[j]);
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
            ans = max(ans, dp[i]);
        cout << m - ans - veg[n - 1] << endl;
    }
    return 0;
}