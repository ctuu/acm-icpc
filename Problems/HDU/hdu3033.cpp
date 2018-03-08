#include <iostream>
#include <array>
#include <vector>
#define N 105
#define M 10005
#define K 15
#define C 100005
#define INF 0x3f3f3f3f
using namespace std;

struct no
{
    int b, c;
    no() = default;
    no(int a, int b)
    {
        this->b = a;
        this->c = b;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        array<vector<no>, K> va;
        array<array<int, M>, K> dp;
        for (int i = 1; i <= n; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            va[a].push_back(no(b, c));
        }
        for (auto &i : dp)
            i.fill(-INF);
        dp[0].fill(0);
        int ct;
        for (int i = 1; i <= k; ++i)
        {
            ct = va[i].size();
            for (int j = 0; j < ct; ++j)
                for (int l = m; l >= va[i][j].b; --l)
                        dp[i][l] = max(dp[i][l], max(dp[i - 1][l - va[i][j].b] + va[i][j].c, dp[i][l - va[i][j].b] + va[i][j].c));
        }
        if (dp[k][m] < 0)
            cout << "Impossible" << endl;
        else
            cout << dp[k][m] << endl;
    }
    return 0;
}