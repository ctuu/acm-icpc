#include <array>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 13;
const int M = 107;
int d[3] = {-1, 0, 1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    array<array<int, M>, N> mtx, dp;
    array<array<bool, M>, N> op;
    while (cin >> n >> m)
    {
        for (auto &i : dp)
            i.fill(INF);
        for (auto &i : op)
            i.fill(0);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> mtx[i][j];
        for (int i = 1; i <= n; ++i)
        {
            op[i][m] = 1;
            dp[i][m] = mtx[i][m];
        }
        for (int j = m; j > 1; --j)
            for (int i = 1; i <= n; ++i)
                if (op[i][j])
                    for (int k = 0; k < 3; ++k)
                    {
                        int cx = i + d[k];
                        cx = cx == 0 ? n : cx;
                        cx = cx == n + 1 ? 1 : cx;
                        int cy = j - 1;
                        op[cx][cy] = 1;
                        dp[cx][cy] = min(dp[cx][cy], dp[i][j] + mtx[cx][cy]);
                    }
        int ax = 1, ay = 1;
        for (int i = 2; i <= n; ++i)
            ax = dp[ax][1] > dp[i][1] ? i : ax;
        int ans = dp[ax][1];
        while (ay < m)
        {
            cout << ax << " ";
            int nx = INF;
            for (int i = 0; i < 3; ++i)
            {
                int cy = ay + 1;
                int cx = ax + d[i];
                cx = cx == 0 ? n : cx;
                cx = cx == n + 1 ? 1 : cx;
                if (dp[ax][ay] == dp[cx][cy] + mtx[ax][ay])
                    nx = nx < cx ? nx : cx;
            }
            ax = nx;
            ay++;
        }
        cout << ax << endl;
        cout << ans << endl;
    }
    return 0;
}