#include <bits/stdc++.h>
#define N 1000
#define V 1000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, v;
        array<pair<int, int>, N + 1> bo;
        cin >> n >> v;
        for (int i = 0; i < n; ++i)
            cin >> bo[i].first;
        for (int i = 0; i < n; ++i)
            cin >> bo[i].second;
        array<int, V + 1> dp;
        dp.fill(0);
        for (int i = 0; i < n; ++i)
            for (int j = v; j >= bo[i].second; --j)
                dp[j] = max(dp[j], dp[j - bo[i].second] + bo[i].first);
        cout << dp[v] << endl;
    }
    return 0;
}