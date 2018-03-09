/*
Sample Input
4 4 3 10
N 1 1 1 1
W 1 1 3 2
W 2 1 2 4
4 4 3 10
N 1 1 1 1
W 1 1 3 2
W 1 1 2 4

Sample Output
9
Bad luck!
*/

#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
array<array<array<bool, 1030>, 110>, 110> tmap;
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
        for (auto &i : tmap)
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
                for (size_t k = 0; k < bs.size(); ++k)
                {
                    switch (c)
                    {
                    case 'N':
                        if (bs[k].x - v > -1 && !vis[bs[k].x - v][bs[k].y])
                        {
                            bs[k].x -= v;
                            tmap[bs[k].x][bs[k].y][j] = 1;
                        }
                        else
                            bs.erase(bs.begin() + k);
                        break;
                    case 'S':
                        if (bs[k].x - v <= n && !vis[bs[k].x + v][bs[k].y])
                        {
                            bs[k].x += v;
                            tmap[bs[k].x][bs[k].y][j] = 1;
                        }
                        else
                            bs.erase(bs.begin() + k);
                        break;
                    case 'W':
                        if (bs[k].y - v > -1 && !vis[bs[k].x][bs[k].y - v])
                        {
                            bs[k].y -= v;
                            tmap[bs[k].x][bs[k].y][j] = 1;
                        }
                        else
                            bs.erase(bs.begin() + k);
                        break;
                    case 'E':
                        if (bs[k].y + v <= m && !vis[bs[k].x][bs[k].y + v])
                        {
                            bs[k].y += v;
                            tmap[bs[k].x][bs[k].y][j] = 1;
                        }
                        else
                            bs.erase(bs.begin() + k);
                        break;
                    }
                }
                ++e;
                if (e < t)
                    continue;
                else
                {
                    e = 0;
                    switch (c)
                    {
                    case 'N':
                        if (x - v > -1 && !vis[x - v][y])
                        {
                            tmap[x - v][y][j] = 1;
                            bs.push_back(Bu(x - v, y));
                        }
                        break;
                    case 'S':
                        if (x - v <= n && !vis[x + v][y])
                        {
                            tmap[x + v][y][j] = 1;
                            bs.push_back(Bu(x + v, y));
                        }
                        break;
                    case 'W':
                        if (y - v > -1 && !vis[x][y - v])
                        {
                            tmap[x][y - v][j] = 1;
                            bs.push_back(Bu(x, y - v));
                        }
                        break;
                    case 'E':
                        if (y + v <= m && !vis[x][y + v])
                        {
                            tmap[x][y + v][j] = 1;
                            bs.push_back(Bu(x, y + v));
                        }
                        break;
                    }
                }
            }
        }
        queue<Lo> qu;
        int ctt = 0;
        Lo tmp = Lo(0, 0, d, 0);
        qu.push(tmp);
        int ans = INF;
        while (!qu.empty())
        {
            Lo cu = qu.front();
            qu.pop();
            if (ctt < cu.ti)
            {
                cout << ctt << ":" << endl;
                for (int i = 0; i <= n; ++i, cout << endl)
                    for (int j = 0; j <= m; ++j)
                        cout << tmap[i][j][ctt];
                ctt++;
            }
            if (cu.x == n && cu.y == m)
            {
                ans = d - cu.e;
                break;
            }
            int r[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (int i = 0; i < 5; ++i)
            {
                int cx = cu.x + r[i][0];
                int cy = cu.y + r[i][1];
                if (cx > -1 && cx <= n && cy > -1 && cy <= m && !vis[cx][cy] && !tmap[cx][cy][cu.ti + 1] && cu.e > 0)
                {
                    Lo tmp = Lo(cx, cy, cu.e - 1, cu.ti + 1);
                    qu.push(tmp);
                }
                vis[cx][cy]=1;
            }
        }
        if (ans == INF)
            cout << "Bad luck!" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}