#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ori[18][18] = {0};
    int a[18][18] = {0};
    int tmp[18][18] = {0};
    int b[18][18] = {0};
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> ori[i][j];
    int ans = INF;
    for (int k = 0; k < (1 << m); ++k)
    {
        int tns = k;
        memcpy(a, ori, sizeof(ori));
        memset(tmp,0,sizeof(tmp));
        for (int j = 0; j < m; ++j)
            if (k & (1 << j))
            {
                a[1][j + 1] ^= 1;
                a[1][j] ^= 1;
                a[1][j + 2] ^= 1;
                a[2][j + 1] ^= 1;
                tmp[1][j + 1]++;
            }
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i - 1][j])
                {
                    ++tns;
                    tmp[i][j]++;
                    a[i][j] ^= 1;
                    a[i - 1][j] ^= 1;
                    a[i][j - 1] ^= 1;
                    a[i + 1][j] ^= 1;
                    a[i][j + 1] ^= 1;
                }
        bool fl = 0;
        for (int j = 1; j <= m; ++j)
            if (a[n][j])
                fl = 1;
        if (!fl && tns < ans)
        {
            ans = tns;
            memcpy(b, tmp, sizeof(tmp));
        }
    }

    if (ans == INF)
        cout << "IMPOSSIBLE" << endl;
    else
        for (int i = 1; i <= n; ++i, cout << endl)
            for (int j = 1; j <= m; ++j)
                cout << b[i][j] << ' ';
    return 0;
}