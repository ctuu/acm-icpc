#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define INF 0x3f3f3f3f
#define N 103
#define M 102
#define L 1002
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        array<pair<int, int>, N> va;
        for (int i = 0; i < n; ++i)
            cin >> va[i].first >> va[i].second;
        array<array<int, L>, M> dp;
        for (auto &i : dp)
            i.fill(-INF);
        dp[0].fill(0);
        for (int i = 0; i < n; ++i)
            for (int j = m; j >= 1; --j)
                for (int k = l; k >= va[i].first; --k)
                    dp[j][k] = max(dp[j][k], dp[j - 1][k - va[i].first] + va[i].second);
        cout << max(dp[m][l], 0) << endl;
    }
    return 0;
}