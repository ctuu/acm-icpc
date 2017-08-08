#include <iostream>
#include <array>
#define N 105
#define M 105
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    array<array<int, M>, N> va, dp;
    for (auto &i : va)
        i.fill(0);
    while (cin >> n >> m && n && m)
    {
        for (auto &i : dp)
            i.fill(0);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
                cin >> va[i][j];
            for (int l = 1; l <= m; ++l)
                dp[i][l] = dp[i - 1][l];
            for (int j = 1; j <= m; ++j)
                for (int k = m; k >= j; --k)
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - j] + va[i][j]);
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}