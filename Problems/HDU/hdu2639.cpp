#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#define N 105
#define V 1005
#define K 35
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, v, k;
        cin >> n >> v >> k;
        array<pair<int, int>, N> va;
        for (int i = 0; i < n; ++i)
            cin >> va[i].first;
        for (int i = 0; i < n; ++i)
            cin >> va[i].second;
        array<array<int, K>, V> dp;
        array<int, V> d1, d2;
        for (auto &i : dp)
            i.fill(0);
        for (int i = 0; i < n; ++i)
            for (int j = v; j >= va[i].second; --j)
            {
                for (int p = 1; p <= k; ++p)
                {
                    d1[p] = dp[j][p];
                    d2[p] = dp[j - va[i].second][p] + va[i].first;
                }
                d1[k + 1] = d2[k + 1] = -1;
                int x = 1, y = 1, z = 1;
                while ((d1[x] != -1 || d2[y] != -1) && z <= k)
                {
                    if (d1[x] > d2[y])
                    {
                        dp[j][z] = d1[x];
                        ++x;
                    }
                    else
                    {
                        dp[j][z] = d2[y];
                        y++;
                    }
                    if (dp[j][z - 1] != dp[j][z])
                        ++z;
                }
            }
            cout << dp[v][k] << endl;
    }
    return 0;
}