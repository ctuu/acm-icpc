#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Lo
{
    int x, y, t;
    Lo() {}
    Lo(int x, int y, int t) : x(x), y(y), t(t) {}
};
struct Castle
{
    int c, t, v, x, y;
};
struct Bu
{
    int x, y;
    Bu(int x, int y) : x(x), y(y) {}
};
array<array<array<bool, 1003>, 110>, 110> mrk;
array<array<bool, 110>, 110> vis;
array<Castle, 103> ca;
int r[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, k, d;
int bfs()
{
    queue<Lo> qu;
    qu.push(Lo(0, 0, 0));
    mrk[0][0][0] = true;
    int ans = INF;
    while (!qu.empty())
    {
        Lo cu = qu.front();
        qu.pop();
        if (d < cu.t)
            continue;
        if (cu.x == n && cu.y == m)
            return cu.t;
        for (int i = 0; i < 5; ++i)
        {
            int cx = cu.x + r[i][0];
            int cy = cu.y + r[i][1];
            int ct = cu.t + 1;
            if (cx > -1 && cx <= n && cy > -1 && cy <= m && !vis[cx][cy] && !mrk[cx][cy][ct])
            {
                mrk[cx][cy][ct] = true;
                qu.push(Lo(cx, cy, ct));
            }
        }
    }
    return ans;
}
void pre_set()
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= d; j += ca[i].t)
        {
            for (int k = 1;; k++)
            {
                int x = ca[i].x + r[ca[i].c][0] * k;
                int y = ca[i].y + r[ca[i].c][1] * k;
                if (x < 0 || x > n || y < 0 || y > m || vis[x][y])
                    break;
                if (k % ca[i].v == 0)
                    mrk[x][y][j + k / ca[i].v] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m >> k >> d)
    {
        for (auto &i : mrk)
            for (auto &j : i)
                j.fill(0);
        for (auto &i : vis)
            i.fill(0);

        for (int i = 0; i < k; ++i)
        {
            char c;
            cin >> c >> ca[i].t >> ca[i].v >> ca[i].x >> ca[i].y;
            if (c == 'N')
                ca[i].c = 0;
            if (c == 'S')
                ca[i].c = 1;
            if (c == 'E')
                ca[i].c = 2;
            if (c == 'W')
                ca[i].c = 3;
            vis[ca[i].x][ca[i].y] = 1;
        }
        pre_set();
        int ans = bfs();
        if (ans == INF)
            cout << "Bad luck!" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}