#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
array<array<array<bool, 1030>, 110>, 110> map;
array<array<array<bool, 1030>, 110>, 110> mrk;
array<array<bool, 110>, 110> vis;
struct Lo
{
    int x, y, e, ti;
    Lo() {}
    Lo(int x, int y, int e, int ti) : x(x), y(y), e(e), ti(ti) {}
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
        for (auto &i : map)
            for (auto &j : i)
                j.fill(0);
        for (auto &i : mrk)
            for (auto &j : i)
                j.fill(0);
        for (auto &i : vis)
            i.fill(0);
        for (int i = 0; i < k; ++i)
        {
            char c;
            int t, v, x, y;
            cin >> c >> t >> v >> x >> y;
            vector<Bu> bs;
            vis[x][y] = 1;
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
                        map[bs[k].x][bs[k].y][j] = 1;
                }
                if (++e < t)
                    continue;
                if (c == 'N' && (x - v < 0 || vis[x - v][y]))
                    continue;
                if (c == 'S' && (x - v > n || vis[x + v][y]))
                    continue;
                if (c == 'W' && (y - v < 0 || vis[x][y - v]))
                    continue;
                if (c == 'E' && (y + v > m || vis[x][y + v]))
                    continue;
                e = 0;
                map[x][y][j] = 1;
                bs.push_back(Bu(x, y));
            }
        }
        queue<Lo> qu;
        Lo tmp = Lo(0, 0, d, 0);
        qu.push(tmp);
        // mrk[0][0][0] = 1;
        int ans = INF;
        int ctt = 0;
        // while (!qu.empty())
        // {
        //     Lo cu = qu.front();
        //     qu.pop();
        //     if (ctt < cu.ti)
        //     {
        //         cout << ctt << ": map" << endl;
        //         for (int i = 0; i <= n; ++i, cout << endl)
        //             for (int j = 0; j <= m; ++j)
        //                 cout << map[i][j][ctt];
        //         cout << ctt << "------mak------" << endl;
        //         for (int i = 0; i <= n; ++i, cout << endl)
        //             for (int j = 0; j <= m; ++j)
        //                 cout << mrk[i][j][ctt];
        //         cout << endl;
        //         ctt++;
        //     }
        //     if (cu.x == n && cu.y == m)
        //     {
        //         ans = d - cu.e;
        //         break;
        //     }
        //     int r[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        //     for (int i = 0; i < 5; ++i)
        //     {
        //         int cx = cu.x + r[i][0];
        //         int cy = cu.y + r[i][1];
        //         int cti = cu.ti + 1;
        //         if (cx > -1 && cx <= n && cy > -1 && cy <= m && !vis[cx][cy] && !map[cx][cy][cti] && !mrk[cx][cy][cti] && cu.e > 0)
        //         {
        //             Lo tmp = Lo(cx, cy, cu.e - 1, cti);
        //             mrk[cx][cy][cti] = 1;
        //             qu.push(tmp);
        //         }
        //         vis[cx][cy] = 1;
        //     }
        // }
        while (ctt < d)
        {
            // cout << ctt << ": map" << endl;
            // for (int i = 0; i <= n; ++i, cout << endl)
            //     for (int j = 0; j <= m; ++j)
            //         cout << map[i][j][ctt];
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