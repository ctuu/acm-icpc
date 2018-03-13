#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using PII = pair<int, int>;
struct Po
{
    int x, y;
    Po(int tx, int ty) : x(tx), y(ty) {}
};
int n, m, ans, tme;
vector<PII> gho;
array<array<bool, 803>, 803> mz;
array<array<array<bool, 803>, 803>, 2> vis;
bool chk(Po cu)
{
    if (cu.x < 0 || cu.x >= n || cu.y < 0 || cu.y >= m)
        return 0;
    for (auto g : gho)
    {
        int tmp = abs(cu.x - g.first) + abs(cu.y - g.second);
        if (tmp <= 2 * tme || !mz[cu.x][cu.y])
            return 0;
    }
    return 1;
}
int r[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool bfs(queue<Po> &qc, int num, bool mg)
{
    queue<Po> qu = qc;
    for (int i = 0; i < num; ++i)
    {
        while (!qu.empty())
        {
            Po cu = qu.front();
            qc.pop();
            qu.pop();
            if (!chk(cu))
                continue;
            for (int i = 0; i < 4; ++i)
            {
                int cx = cu.x + r[i][0];
                int cy = cu.y + r[i][1];
                Po tmp = Po(cx, cy);
                if (!chk(tmp) || vis[mg][cx][cy])
                    continue;
                qc.push(tmp);
                vis[mg][cx][cy] = 1;
                if (vis[0][cx][cy] && vis[1][cx][cy])
                    return 1;
            }
        }
        qu = qc;
    }
    return 0;
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        for (auto &i : mz)
            i.fill(1);
        for (auto &i : vis)
            for(auto &j : i)
            j.fill(0);
        ans = -1;
        tme = 0;
        char ch;
        gho.clear();
        queue<Po> qm, qg;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> ch;
                if (ch == 'X')
                    mz[i][j] = 0;
                if (ch == 'Z')
                    gho.push_back(make_pair(i, j));
                if (ch == 'M')
                    qm.push(Po(i, j));
                if (ch == 'G')
                    qg.push(Po(i, j));
            }
        while (!qm.empty() || !qg.empty())
        {
            ++tme;
            if (bfs(qm, 3, 1) || bfs(qg, 1, 0))
            {
                ans = tme;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}