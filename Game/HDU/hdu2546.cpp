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
        m -= 5;
        array<int, M> dp;
        dp.fill(0);
        for (int i = 0; i < n - 1; ++i)
            for (int j  = m; j >= veg[i]; --j)
                dp[j] = max(dp[j], dp[j - veg[i]] + veg[i]);
        cout << m - dp[m] + 5 - veg[n - 1] << endl;
    }
    return 0;
}