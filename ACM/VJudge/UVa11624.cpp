#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
struct Po
{
    int x, y, t;
    Po() {}
    Po(int x, int y, int t) : x(x), y(y), t(t) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    while (T--)
    {
        array<array<char, 1100>, 1100> maze;
        array<array<bool, 1100>, 1100> vis;
        for (auto &i : vis)
            i.fill(0);
        vector<Po> frl;
        queue<Po> qu;
        int ans = INF;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> maze[i][j];
                if (maze[i][j] == 'F')
                    frl.push_back(Po(i, j, 0));
                if (maze[i][j] == 'J')
                {
                    vis[i][j] = 1;
                    qu.push(Po(i, j, 0));
                }
            }
        for (auto i : frl)
            qu.push(i);
        while (!qu.empty())
        {
            Po cu = qu.front();
            qu.pop();
            int &x = cu.x, &y = cu.y, &t = cu.t;
            if (maze[x][y] == 'J')
            {
                if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                {
                    ans = min(ans, t+1);
                    break;
                }
                for (int i = -1; i < 2; i += 2)
                {
                    if (vis[x + i][y]==0 && maze[x + i][y] == '.')
                    {
                        qu.push(Po(x + i, y, t + 1));
                        maze[x + i][y] = 'J';
                        vis[x + i][y] = 1;
                    }
                }
                for (int i = -1; i < 2; i += 2)
                {
                    if (vis[x][y + i]==0 && maze[x][y + i] == '.')
                    {
                        qu.push(Po(x, y + i, t + 1));
                        maze[x][y + i] = 'J';
                        vis[x][y + i] = 1;
                    }
                }
            }
            else if (maze[x][y] == 'F')
            {
                for (int i = -1; i < 2; i += 2)
                    if (x + i < n && x + i > -1 && maze[x + i][y] != '#' && maze[x + i][y] != 'F')
                    {
                        qu.push(Po(x + i, y, t + 1));
                        maze[x + i][y] = 'F';
                        vis[x + i][y] = 1;
                    }
                for (int i = -1; i < 2; i += 2)
                    if (y + i < n && y + i > -1 && maze[x][y + i] != '#' && maze[x][y + i] != 'F')
                    {
                        qu.push(Po(x, y + i, t + 1));
                        maze[x][y + i] = 'F';
                        vis[x][y + i] = 1;
                    }
            }
            // for (int i = 0; i < n; ++i, cout << endl)
            //     for (int j = 0; j < m; ++j)
            //         cout << maze[i][j];
        }
        if (ans == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}