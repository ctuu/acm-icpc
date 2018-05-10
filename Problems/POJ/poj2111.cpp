#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 367;
struct Nd
{
    int id, x, y;
};

int d[8][2] = {-2, -1, -2, 1, -1, -2, 1, -2, 2, -1, 2, 1, -1, 2, 1, 2};

bool cmp(Nd a, Nd b)
{
    return a.id > b.id;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dp[N][N];
    int mtx[N][N];
    vector<Nd> nds;
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> mtx[i][j];
            nds.push_back(Nd{mtx[i][j], i, j});
        }
    sort(nds.begin(), nds.end(), cmp);
    for (int i = 0; i < n * n; ++i)
    {
        int x = nds[i].x, y = nds[i].y;
        for (int j = 0; j < 8; ++j)
        {
            int cx = x + d[j][0], cy = y + d[j][1];
            if (cx >= n || cx < 0 || cy >= n || cy < 0)
                continue;
            if (mtx[cx][cy] < mtx[x][y])
                dp[cx][cy] = max(dp[cx][cy], dp[x][y] + 1);
        }
    }
    int ax = 0, ay = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (dp[i][j] > dp[ax][ay])
            {
                ax = i;
                ay = j;
            }
            else if (dp[i][j] == dp[ax][ay] && mtx[i][j] < mtx[ax][ay])
            {
                ax = i;
                ay = j;
            }

    cout << dp[ax][ay] + 1 << endl;

    while (dp[ax][ay])
    {
        cout << mtx[ax][ay] << endl;
        vector<Nd> td;
        for (int j = 0; j < 8; ++j)
        {
            int cx = ax + d[j][0], cy = ay + d[j][1];
            if (cx >= n || cx < 0 || cy >= n || cy < 0)
                continue;
            if (dp[cx][cy] == dp[ax][ay] - 1)
                td.push_back(Nd{mtx[cx][cy], cx, cy});
        }
        sort(td.begin(), td.end(), cmp);
        ax = (td.end() - 1)->x;
        ay = (td.end() - 1)->y;
    }
    cout << mtx[ax][ay] << endl;
    return 0;
}