#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
array<array<char, 53>, 53> ar;
int n, m, sx, sy, ex, ey;
int ct = 0;
void dfs(string s, int x, int y, char u, char d, char l, char r)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (s.size() == 0)
        return;
    if (ar[x][y] == '#')
        return;
    if (ar[x][y] == 'E')
    {
        ct++;
        return;
    }
    char a = s[0];
    if (a == u)
        dfs(s.substr(1, s.size()), x - 1, y, u, d, l, r);
    else if (a == d)
        dfs(s.substr(1, s.size()), x + 1, y, u, d, l, r);
    else if (a == l)
        dfs(s.substr(1, s.size()), x, y - 1, u, d, l, r);
    else if (a == r)
        dfs(s.substr(1, s.size()), x, y + 1, u, d, l, r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'S')
                sx = i, sy = j;
            if (ar[i][j] == 'E')
                ex = i, ey = j;
        }
    string s;
    cin >> s;
    dfs(s, sx, sy, '1', '2', '3', '0');
    dfs(s, sx, sy, '1', '2', '0', '3');
    dfs(s, sx, sy, '1', '3', '2', '0');
    dfs(s, sx, sy, '1', '3', '0', '2');
    dfs(s, sx, sy, '1', '0', '2', '3');
    dfs(s, sx, sy, '1', '0', '3', '2');
    dfs(s, sx, sy, '2', '1', '3', '0');
    dfs(s, sx, sy, '2', '1', '0', '3');
    dfs(s, sx, sy, '2', '3', '0', '1');
    dfs(s, sx, sy, '2', '3', '1', '0');
    dfs(s, sx, sy, '2', '0', '1', '3');
    dfs(s, sx, sy, '2', '0', '3', '1');
    dfs(s, sx, sy, '3', '1', '2', '0');
    dfs(s, sx, sy, '3', '1', '0', '2');
    dfs(s, sx, sy, '3', '2', '1', '0');
    dfs(s, sx, sy, '3', '2', '0', '1');
    dfs(s, sx, sy, '3', '0', '1', '2');
    dfs(s, sx, sy, '3', '0', '2', '1');
    dfs(s, sx, sy, '0', '1', '2', '3');
    dfs(s, sx, sy, '0', '1', '3', '2');
    dfs(s, sx, sy, '0', '2', '3', '1');
    dfs(s, sx, sy, '0', '2', '1', '3');
    dfs(s, sx, sy, '0', '3', '1', '2');
    dfs(s, sx, sy, '0', '3', '2', '1');
    cout << ct;
    return 0;
}