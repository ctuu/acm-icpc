#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
struct Su
{
    int s, n, m, t;
    Su(int s, int n, int m, int t) : s(s), n(n), m(m), t(t) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, n, m;
    // array<array<array<bool, 130>, 130>, 130> vis;
    int vis[103][103][103];
    while (cin >> s >> n >> m)
    {
        memset(vis,0,sizeof(vis));
        // for (auto &i : vis)
        //     for (auto &j : i)
        //         j.fill(0);
        if (s == 0 && n == 0 && m == 0)
            break;
        queue<Su> qu;
        if (s % 2 == 0)
            qu.push(Su(s, 0, 0, 0));
        vis[s][n][m] = 1;
        int ans = -1;
        while (!qu.empty())
        {
            int ts, tn, tm;
            Su cu = qu.front();
            qu.pop();
            // cout << cu.s << " " << cu.n << " " << cu.m << endl;
            if ((cu.n == s / 2 && cu.m == s / 2) || (cu.n == s / 2 && cu.s == s / 2) || (cu.s == s / 2 && cu.m == s / 2))
            {
                ans = cu.t;
                break;
            }
            //stn
            ts = cu.s + cu.n > n ? cu.s + cu.n - n : 0;
            tn = cu.s + cu.n > n ? n : cu.s + cu.n;
            if (!vis[ts][tn][cu.m])
            {
                qu.push(Su(ts, tn, cu.m, cu.t + 1));
                vis[ts][tn][cu.m] = 1;
            }
            //stm
            ts = cu.s + cu.m > m ? cu.s + cu.m - m : 0;
            tm = cu.s + cu.m > m ? m : cu.s + cu.m;
            if (!vis[ts][cu.n][tm])
            {
                qu.push(Su(ts, cu.n, tm, cu.t + 1));
                vis[ts][cu.n][tm] = 1;
            }
            //nts
            tn = cu.n + cu.s > s ? cu.n + cu.s - s : 0;
            ts = cu.n + cu.s > s ? s : cu.s + cu.n;
            if (!vis[ts][tn][cu.m])
            {
                qu.push(Su(ts, tn, cu.m, cu.t + 1));
                vis[ts][tn][cu.m] = 1;
            }
            //ntm
            tn = cu.n + cu.m > m ? cu.n + cu.m - m : 0;
            tm = cu.n + cu.m > m ? m : cu.m + cu.n;
            if (!vis[cu.s][tn][tm])
            {
                qu.push(Su(cu.s, tn, tm, cu.t + 1));
                vis[cu.s][tn][tm] = 1;
            }
            //mts
            tm = cu.m + cu.s > s ? cu.m + cu.s - s : 0;
            ts = cu.m + cu.s > s ? s : cu.s + cu.m;
            if (!vis[ts][cu.n][tm])
            {
                qu.push(Su(ts, cu.n, tm, cu.t + 1));
                vis[ts][cu.n][tm] = 1;
            }
            //mtn
            tm = cu.m + cu.n > n ? cu.m + cu.n - n : 0;
            tn = cu.m + cu.n > n ? n : cu.n + cu.m;
            if (!vis[cu.s][tn][tm])
            {
                qu.push(Su(cu.s, tn, tm, cu.t + 1));
                vis[cu.s][tn][tm] = 1;
            }
        }
        if (ans == -1)
            cout << "NO" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}