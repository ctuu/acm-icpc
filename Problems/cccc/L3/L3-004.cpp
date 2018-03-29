#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct No
{
    int x, y, z;
};
int d[6][3]{-1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1};
array<array<array<bool, 130>, 1300>, 65> zl;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : zl)
        for (auto &j : i)
            j.fill(0);
    int m, n, l, T;
    cin >> m >> n >> l >> T;
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                cin >> zl[i][j][k];
    int ans = 0;
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
            {
                if (zl[i][j][k] == 0)
                    continue;
                int tj = 1;
                queue<No> qu;
                qu.push(No{i, j, k});
                zl[i][j][k] = 0;
                while (!qu.empty())
                {
                    auto c = qu.front();
                    qu.pop();
                    for (int b = 0; b < 6; ++b)
                    {
                        int cx = c.x + d[b][0];
                        int cy = c.y + d[b][1];
                        int cz = c.z + d[b][2];
                        if (cx > -1 && cx < l && cy > -1 && cy < m && cz > -1 && cz < n)
                        {
                            if (zl[cx][cy][cz])
                            {
                                tj++;
                                zl[cx][cy][cz] = 0;
                                qu.push(No{cx, cy, cz});
                            }
                        }
                    }
                }
                if (tj >= T)
                    ans+=tj;
            }
    cout << ans << endl;
    return 0;
}