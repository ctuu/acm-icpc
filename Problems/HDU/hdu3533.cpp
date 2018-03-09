#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
bool map[103][103][1003], mrk[103][103][1003], vis[110][110];
struct Lo
{
    int x, y, t;
    Lo() {}
    Lo(int x, int y, int t) : x(x), y(y), t(t) {}
};
struct Bu
{
    int x, y;
    Bu(int x, int y) : x(x), y(y) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, d;
    while (cin >> m >> n >> k >> d)
    {
        memset(map, false, sizeof(map));
        memset(mrk, false, sizeof(mrk));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < k; ++i)
        {
            char c;
            int t, v, x, y;
            cin >> c >> t >> v >> x >> y;
            vector<Bu> bs;
            vis[x][y] = true;
            int e = t;
            for (int j = 0; j <= d; ++j)
            {
                for (std::size_t k = 0; k < bs.size(); ++k)
                {
                    if (c == 'N')
                        bs[k].x -= v;
                    if (c == 'S')
                        bs[k].x += v;
                    if (c == 'W')
                        bs[k].y -= v;
                    if (c == 'E')
                        bs[k].y += v;
                    if (bs[k].x > -1 && bs[k].y <= n && bs[k].y > -1 && bs[k].y <= m && !vis[bs[k].x][bs[k].y])
                        map[bs[k].x][bs[k].y][j] = true;
                }
                if (++e < t)
                    continue;
                if (c == 'N' && (x - v < 0 || vis[x - v][y]))
                    continue;
                if (c == 'S' && (x + v > n || vis[x + v][y]))
                    continue;
                if (c == 'W' && (y - v < 0 || vis[x][y - v]))
                    continue;
                if (c == 'E' && (y + v > m || vis[x][y + v]))
                    continue;
                e = 0;
                map[x][y][j] = true;
                bs.push_back(Bu(x, y));
            }
        }
        queue<Lo> qu;
        qu.push(Lo(0, 0, 0));
        mrk[0][0][0] = true;
        int ans = INF;
        while (!qu.empty())
        {
            Lo cu = qu.front();
            qu.pop();
            if (cu.x == n && cu.y == m)
            {
                ans = cu.t;
                break;
            }
            if (n - cu.x + m - cu.y > d - cu.t)
                continue;
            int r[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int i = 0; i < 5; ++i)
            {
                int cx = cu.x + r[i][0];
                int cy = cu.y + r[i][1];
                int ct = cu.t + 1;
                if (cx > -1 && cx <= n && cy > -1 && cy <= m && !vis[cx][cy] && !map[cx][cy][ct] && !mrk[cx][cy][ct])
                {
                    Lo tmp = Lo(cx, cy, ct);
                    mrk[cx][cy][ct] = true;
                    qu.push(tmp);
                }
            }
        }
        int ctt = 0;
        while (ctt < d)
        {
            cout << ctt << "------mak------" << endl;
            for (int i = 0; i <= n; ++i, cout << endl)
                for (int j = 0; j <= m; ++j)
                    cout << mrk[i][j][ctt];
            cout << endl;
            ctt++;
        }

        if (ans == INF)
            cout << "Bad luck!" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
