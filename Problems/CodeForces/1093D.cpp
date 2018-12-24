#include <iostream>
#include <array>
#include <vector>
using namespace std;
const int N = 3e5 + 7;
const int MOD = 998244353;
using E = array<vector<int>, N>;
int le, ri;
long long ans;
array<int, N> vis;
array<vector<int>, N> edg;
void dfs(int x)
{
    le = vis[x] > 0 ? le + 1 : le;
    ri = vis[x] < 0 ? ri + 1 : ri;
    for (auto i : edg[x])
    {
        if (vis[i] == vis[x])
        {
            ans = 0;
            return;
        }
        else if (vis[i] == 0)
        {
            vis[i] = -vis[x];
            dfs(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vis.fill(0);
    int t, offset = 0;
    cin >> t;
    while (t--)
    {
        int n, m;
        ans = 1;
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            a += offset;
            b += offset;
            edg[a].push_back(b);
            edg[b].push_back(a);
        }
        for (int i = 1 + offset; i <= n + offset; ++i)
        {
            if (vis[i])
                continue;
            le = ri = 0;
            long long tl = 1, tr = 1;
            vis[i] = 1;
            dfs(i);
            while (le--)
                tl = (tl << 1) % MOD;
            while (ri--)
                tr = (tr << 1) % MOD;
            ans = (ans * (tl + tr) % MOD) % MOD;
        }
        cout << ans << '\n';
        offset += n;
    }
    return 0;
}