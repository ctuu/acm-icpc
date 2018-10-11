#include <array>
#include <iostream>
using namespace std;
const int N = 1000 + 7;
const int M = 1000 + 7;
array<array<char, M>, N> g;
array<array<bool, M>, N> v;
int n, m;
int d[8][2] = {0, 0, 0, 1, 0, 2, 1, 0, 1, 2, 2, 0, 2, 1, 2, 2};
int w[4][2] = {0, 1, 1, 1, 1, 0, 1, -1};
bool chk(int x, int y)
{
    if (x + 2 < n && y + 2 < m)
    {
        for (int i = 0; i < 8; ++i)
        {
            int cx = x + d[i][0];
            int cy = y + d[i][1];
            if (g[cx][cy] != '#')
            {
                if (!v[x][y])
                    return false;
                else
                    return true;
            }
        }
        if (g[x + 1][y + 1] == '#' && !v[x + 1][y + 1])
        {
            bool fl = 1;
            for (int i = 0; i < 4; ++i)
            {
                fl = 1;
                for (int j = 0; j < 8; ++j)
                {
                    int cx = x + w[i][0] + d[j][0];
                    int cy = y + w[i][1] + d[j][1];
                    if (cx < 0 || cy < 0 || cx >= n || cy >= m)
                    {
                        fl = 0;
                        break;
                    }
                    if (g[cx][cy] != '#')
                    {
                        fl = 0;
                        break;
                    }
                    v[cx][cy] = 1;
                }
                if (fl)
                    break;
            }
            if (!fl)
                return false;
        }
        for (int i = 0; i < 8; ++i)
        {
            int cx = x + d[i][0];
            int cy = y + d[i][1];
            v[cx][cy] = 1;
        }
    }
    else if (!v[x][y])
        return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (auto &i : v)
        i.fill(0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == '#')
                if (!chk(i, j))
                {
                    cout << "NO" << endl;
                    return 0;
                }
    cout << "YES" << endl;
    return 0;
}

