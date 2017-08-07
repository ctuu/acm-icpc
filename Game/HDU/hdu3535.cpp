#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#define N 105
#define T 105
#define M 100
#define CI 100
#define GI 100
#define INF 0X3F3F3F3F
using namespace std;
struct no
{
    int ci, gi;
    no() = default;
    no(int a, int b)
    {
        this->ci = a;
        this->gi = b;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    while (cin >> n >> t)
    {
        int mt = t;
        array<vector<no>, N> va;
        array<array<int, N>, T> dp;
        for (auto &i : dp)
            i.fill(0);
        for (int i = 1; i <= n; ++i)
        {
            int m, s, mm = INF;
            cin >> m >> s;
            for (int j = 0; j < m; ++j)
            {
                int ci, gi;
                cin >> ci >> gi;
                va[i].push_back(no(ci, gi));
                if (s == 0)
                    mm = min(ci, mm);
            }
            //0
            for (int j = 0; j <= t; ++j)
                dp[i][j] = dp[i - 1][j];
            if (s == 0)
            {
                mt -= mm;
                for (int j = 0; j <= t; ++j)
                    dp[i][j] = -INF;
                for (int j = 0; j < m; ++j)
                    for (int k = t; k >= va[i][j].ci; --k)
                        dp[i][k] = max(dp[i][k], max(dp[i][k - va[i][j].ci] + va[i][j].gi, dp[i - 1][k - va[i][j].ci] + va[i][j].gi));
            }
            //1
            else if (s == 1)
            {
                for (int j = 0; j < m; ++j)
                    for (int k = t; k >= va[i][j].ci; --k)
                        dp[i][k] = max(dp[i][k], dp[i - 1][k - va[i][j].ci] + va[i][j].gi);
            }
            //2
            else
            {
                for (int j = 0; j < m; ++j)
                    for (int k = t; k >= va[i][j].ci; --k)
                        dp[i][k] = max(dp[i][k], dp[i][k - va[i][j].ci] + va[i][j].gi);
            }
        }
        // if (mt < 0)
        // {
        //     cout << -1 << endl;
        //     continue;
        // }
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= t; ++j)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << dp[n][t] << endl;
    }
    return 0;
}