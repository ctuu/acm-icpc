#include <bits/stdc++.h>
#define N 55
#define V 55
#define M 105
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n > -1)
    {
        int sum = 0;
        vector<int> va;
        for (int i = 0; i < n; ++i)
        {
            int v, m, r = 1;
            cin >> v >> m;
            sum += v * m;
            while (m >= r)
            {
                va.push_back(v * r);
                m -= r;
                r <<= 1;
            }
            while (m)
            {
                while (m < r)
                    r >>= 1;
                va.push_back(v * r);
                m -= r;
            }
        }
        array<int, N * V * M> dp;
        dp.fill(0);
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j = sum; j >= va[i]; --j)
                dp[j] = max(dp[j], dp[j - va[i]] + va[i]);
        cout << sum - dp[sum / 2] << " " << dp[sum / 2] << endl;
    }
    return 0;
}