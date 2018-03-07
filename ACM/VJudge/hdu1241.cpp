#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
array<array<char, 110>, 110> gd;
void dfs(int x, int y)
{
    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j)
            if (x + i > -1 && x + i < n && y + j > -1 && y + j < m && gd[x + i][y + j] == '@')
            {
                // cout << x + i << " _ " << y + j << endl;
                gd[x + i][y + j] = '*';
                dfs(x + i, y + j);
            }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && n)
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> gd[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (gd[i][j] == '@')
                {
                    gd[i][j] = '*';
                    ++ans;
                    dfs(i, j);
                }
            }
        cout << ans << endl;
    }
    return 0;
}