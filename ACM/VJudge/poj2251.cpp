
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct nd
{
    int z, x, y, le;
    nd() = default;
    nd(int z, int x, int y, int le) : z(z), x(x), y(y), le(le) {}
};
const int INF = 0x3f3f3f3f;
char dug[31][31][31];
bool vis[31][31][31];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans, l, r, c;
    while (cin >> l >> r >> c && l)
    {
        ans = INF;
        nd S, E;
        for (int i = 0; i < l; ++i)
            for (int j = 0; j < r; ++j)
                for (int k = 0; k < c; ++k)
                {
                    vis[i][j][k] = 0;
                    cin >> dug[i][j][k];
                    if (dug[i][j][k] == 'S')
                        S = nd(i, j, k, 0);
                }
        queue<nd> q;
        q.push(S);
        while (!q.empty())
        {
            nd tmp = q.front();
            q.pop();
            int z = tmp.z, y = tmp.y, x = tmp.x, le = tmp.le;
            vis[z][x][y] = 1;
            if (dug[z][x][y] == 'E')
            {
                ans = le;
                break;
            }
            if (z + 1 < l && !vis[z + 1][x][y] && dug[z + 1][x][y] != '#')
                q.push(nd(z + 1, x, y, le + 1));
            if (z  > 0 && !vis[z - 1][x][y] && dug[z - 1][x][y] != '#')
                q.push(nd(z - 1, x, y, le + 1));
            if (x > 0 && !vis[z][x - 1][y] && dug[z][x - 1][y] != '#')
                q.push(nd(z, x - 1, y, le + 1));
            if (x + 1 < r && !vis[z][x + 1][y] && dug[z][x + 1][y] != '#')
                q.push(nd(z, x + 1, y, le + 1));
            if (y > 0 && !vis[z][x][y - 1] && dug[z][x][y - 1] != '#')
                q.push(nd(z, x, y - 1, le + 1));
            if (y + 1 < c && !vis[z][x][y + 1] && dug[z][x][y + 1] != '#')
                q.push(nd(z, x, y + 1, le + 1));
        }
        if (ans != INF)
            cout << "Escaped in " << ans << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }
    return 0;
}