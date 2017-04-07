#include <bits/stdc++.h>
#define MNUM 102
#define INF 0x03ffffff
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && n && m)
    {
        array<array<int, MNUM>, MNUM> lj;
        array<int, MNUM> rlj;
        rlj.fill(INF);
        for (auto &i : lj)
            i.fill(0);
        rlj[1] = 0;
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (lj[a][b])
                lj[a][b] = lj[b][a] = min(c, lj[a][b]);
            else
                lj[a][b] = lj[b][a] = c;
        }

        int cur = 1;
        while (cur < n)
        {
            queue<int> mod;
            for (int i = 1; i <= n; ++i)
            {
                if (lj[cur][i])
                {
                    mod.push(i);
                    rlj[i] = min(rlj[i], rlj[cur] + lj[cur][i]);
                    lj[cur][i] = lj[i][cur] = 0;
                }
            }
            int next = mod.front();
            while (!mod.empty())
            {
                int i = mod.front();
                next = (rlj[next] < rlj[i]) ? next : i;
                mod.pop();
            }
            cur = next;
        }
        cout << rlj[n] << endl;
    }
    return 0;
}
