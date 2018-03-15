#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Po
{
    int x, y, z, t;
};
int r[4][2]{-1, 0, 1, 0, 0, -1, 0, 1};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    array<array<array<char, 13>, 13>, 2> mz;
    array<array<array<bool, 13>, 13>, 2> vis;
    while (T--)
    {
        int n, m, t, ans = -1;
        cin >> n >> m >> t;
        for (auto &i : vis)
            for (auto &j : i)
                j.fill(0);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < m; ++k)
                    cin >> mz[i][j][k];
        queue<Po> qu;
        qu.push(Po{0, 0, 0, 0});
        while (!qu.empty())
        {
            auto cu = qu.front();
            qu.pop();
            if (cu.t >= t)
                break;
            for (int i = 0; i < 4; ++i)
            {
                auto tp = cu;
                tp.x = cu.x + r[i][0];
                tp.y = cu.y + r[i][1];
                tp.t++;
                if (tp.x > -1 && tp.x < n && tp.y > -1 && tp.y < m && !vis[tp.z][tp.x][tp.y])
                {
                    vis[tp.z][tp.x][tp.y] = 1;
                    if (mz[tp.z][tp.x][tp.y] == '#')
                    {
                        tp.z = tp.z == 1 ? 0 : 1;
                        if (vis[tp.z][tp.x][tp.y] || mz[tp.z][tp.x][tp.y] == '#')
                            continue;
                        vis[tp.z][tp.x][tp.y] = 1;
                    }
                    if (mz[tp.z][tp.x][tp.y] == 'P')
                    {
                        ans = 1;
                        break;
                    }
                    if (mz[tp.z][tp.x][tp.y] != '*')
                        qu.push(tp);
                }
            }
        }
        if (ans != -1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}