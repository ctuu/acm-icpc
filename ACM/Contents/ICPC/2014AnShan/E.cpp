#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, m, n;
    array<array<int, 105>, 105> ar;
    array<int, 105> sq;
    cin >> T;
    while (T--)
    {
        array<array<int, 53>, 103> dp;
        for (auto &i : dp)
            i.fill(0);
        cin >> n >> m;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> ar[i][j];
        for (int i = 1; i <= n; ++i)
            cin >> sq[i];
        for (int i = 2; i <= n; ++i)
        {
            if (sq[i] > 0)
            {
                if (sq[i - 1] > 0)
                    dp[i][sq[i]] = dp[i - 1][sq[i - 1]] + ar[sq[i - 1]][sq[i]];
                else
                    for (int j = 1; j <= m; ++j)
                        dp[i][sq[i]] = max(dp[i][sq[i]], dp[i - 1][j] + ar[j][sq[i]]);
            }
            else
            {
                if (sq[i - 1] > 0)
                    for (int j = 1; j <= m; ++j)
                        dp[i][j] = max(dp[i][j], dp[i - 1][sq[i - 1]] + ar[sq[i - 1]][j]);
                else
                    for (int j = 1; j <= m; ++j)
                        for (int k = 1; k <= m; ++k)
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + ar[k][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
            ans = max(ans, dp[n][i]);
        cout << ans << endl;
    }
    return 0;
}
