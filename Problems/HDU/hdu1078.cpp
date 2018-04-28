#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
array<array<int, 102>, 102> cty, tns;
int n, k;
int d[4][2]{-1, 0, 1, 0, 0, -1, 0, 1};
int dfs(int x, int y)
{
    if (tns[x][y])
        return tns[x][y];
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int nx = x + d[j][0] * i;
            int ny = y + d[j][1] * i;
            if (nx >= n || nx < 0 || ny >= n || ny < 0)
                continue;
            if (cty[nx][ny] > cty[x][y])
                ans = max(ans, dfs(nx, ny));
        }
    }
    tns[x][y] = ans + cty[x][y];
    return tns[x][y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> k)
    {
        if (n == -1 && k == -1)
            break;
        for (auto &i : tns)
            i.fill(0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> cty[i][j];
        cout << dfs(0, 0) << endl;
    }
    return 0;
}