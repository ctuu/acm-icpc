#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
array<array<bool, 2002>, 2002> a;
array<array<int, 2002>, 2002> b;
void sq(int x, int y, int k);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            b[i][j] += a[i][j];
            sq(i, j, k);
            ans = max(ans, b[i][j]);
        }
    cout << ans;
    return 0;
}
void sq(int x, int y, int k)
{
    for (int i = 1; i < k; ++i)
    {
        int tx = x, ty = y - i;
        for (int j = 0; j < i; ++j, ++ty, --tx)
            if (tx > -1 && ty > -1)
            b[x][y] += a[tx][ty];
        for (int j = 0; j < i; ++j, ++ty, ++tx)
            if (tx > -1 && ty > -1)
            b[x][y] += a[tx][ty];
        for (int j = 0; j < i; ++j, --ty, ++tx)
            if (tx > -1 && ty > -1)
            b[x][y] += a[tx][ty];
        for (int j = 0; j < i; ++j, --ty, --tx)
            if (tx > -1 && ty > -1)
            b[x][y] += a[tx][ty];
    }
}