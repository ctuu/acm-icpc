#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#define N 100
#define T 105
#define M 100
#define CI 100
#define GI 100
#define INF 0X3F3F3F3F
using namespace std;
struct item
{
    int ci, gi;
    item() = default;
    item(int a, int b)
    {
        this->ci = a;
        this->gi = b;
    }
};
struct node
{
    vector<item> it;
    int id;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    while (cin >> n >> t)
    {
        int tm = INF;
        // array<vector<no>, 3> va;
        array<node, N> va;
        for (int i = 0; i < n; ++i)
        {
            int m, s;
            cin >> m >> s;
            va[i].id = s;
            for (int j = 0; j < m; ++j)
            {
                int ci, gi;
                cin >> ci >> gi;
                va[i].it.push_back(no(ci, gi));
            }
        }
        if (tm > t)
        {
            cout << -1 << endl;
            continue;
        }
        array<array<int, 3>, T> dp;
        dp[0].fill(-INF);
        dp[1].fill(0);
        dp[2].fill(0);
        dp[0][0] = 0;
        int ct;
        //0
        ct = va[0].size();
        for (int i = 0; i < ct; ++i)
            for (int j = t; j >= va[0][i].ci; --j)
                dp[0][j] = max(dp[0][j], dp[0][j - va[0][i].ci] + va[0][i].gi);
        //1
        ct = va[1].size();
        for (int i = 0; i <= t; ++i)
            dp[1][i] = dp[0][i];
        for (int i = 0; i < ct; ++i)
            for (int j = t; j >= va[1][i].ci; --j)
                dp[1][j] = max(dp[1][j], dp[0][j - va[1][i].ci] + va[1][i].gi);
        //2
        ct = va[2].size();
        for (int i = 0; i <= t; ++i)
            dp[2][i] = dp[1][i];
        for (int i = 0; i < ct; ++i)
            for (int j = t; j >= va[2][i].ci; --j)
                dp[2][j] = max(dp[2][j], dp[2][j - va[2][i].ci] + va[2][i].gi);
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j <= t; ++j)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        // cout << dp[2][m] << endl;
    }
    return 0;
}