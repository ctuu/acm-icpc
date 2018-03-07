#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
struct Po
{
    int x, y;
    Po() {}
    Po(int x, int y) : x(x), y(y) {}
};
struct It
{
    Po i;
    int s;
    It() {}
    It(Po i, int s) : i(i), s(s) {}
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    for (int i = 0; i < T;)
    {
        int ans = INF;
        cin >> n >> m;
        char mae[13][13];
        vector<Po> ps;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> mae[i][j];
                if (mae[i][j] == '#')
                    ps.push_back(Po(i, j));
            }
        int si = ps.size();
        bool fl = 0;
        for (int i = 0; i < si; ++i)
            for (int j = 0; j < si; ++j)
            {
                char mtp[13][13];
                int tans = -1;
                memcpy(mtp, mae, sizeof(mtp));
                queue<It> qu;
                qu.push(It(ps[i], 0));
                qu.push(It(ps[j], 0));
                mtp[ps[i].x][ps[i].y] = '.';
                mtp[ps[j].x][ps[j].y] = '.';
                while (!qu.empty())
                {
                    It tp = qu.front();
                    int tx = tp.i.x, ty = tp.i.y;
                    qu.pop();
                    tans = max(tans, tp.s);
                    if (tx + 1 < n && mtp[tx + 1][ty] == '#')
                    {
                        qu.push(It(Po(tx + 1, ty), tp.s + 1));
                        mtp[tx + 1][ty] = '.';
                    }
                    if (tx - 1 >= 0 && mtp[tx - 1][ty] == '#')
                    {
                        qu.push(It(Po(tx - 1, ty), tp.s + 1));
                        mtp[tx - 1][ty] = '.';
                    }
                    if (ty + 1 < m && mtp[tx][ty + 1] == '#')
                    {
                        qu.push(It(Po(tx, ty + 1), tp.s + 1));
                        mtp[tx][ty + 1] = '.';
                    }
                    if (ty - 1 >= 0 && mtp[tx][ty - 1] == '#')
                    {
                        qu.push(It(Po(tx, ty - 1), tp.s + 1));
                        mtp[tx][ty - 1] = '.';
                    }
                }
                bool tfl = 1;
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < m; ++j)
                        if (mtp[i][j] == '#')
                            tfl = 0;
                if (tfl)
                {
                    ans = min(ans, tans);
                    fl = 1;
                }
            }
        if (!fl)
            ans = -1;
        cout << "Case " << ++i << ": " << ans << endl;
    }
    return 0;
}