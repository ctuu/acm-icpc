#include <bits/stdc++.h>
#define N 10005
#define M 10005
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    array<pair<int, double>, M> sc;
    array<double, N> dp;
    while (cin >> n >> m && (n || m))
    {
        for (int i = 0; i < m; ++i)
            cin >> sc[i].first >> sc[i].second;
        dp.fill(1.0);
        for (int i = 0; i < m; ++i)
            for (int j = n; j >= sc[i].first; --j)
                dp[j] = min(dp[j], dp[j - sc[i].first] * (1 - sc[i].second));
        cout << setprecision(1) << fixed << (1- dp[n]) * 100 << "%" << endl;
    }
    return 0;
}