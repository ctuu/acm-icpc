#include <map>
#include <stack>
#include <iostream>
#include <array>
#include <vector>
using namespace std;
using E = vector<vector<int>>;
const int N = 3e5 + 7;
const long long MOD = 998244353;
array<int, N> p;
int find(int x)
{
    return p[x] = p[x] == x ? x : p[x] = find(p[x]);
}
void joint(int a, int b)
{
    int i = find(a), j = find(b);
    p[i] = j;
}
array<vector<int>, N> edg;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int ofs = 0;
    array<int, N> tg;
    tg.fill(0);
    for (int i = 0; i <= N; ++i)
        p[i] = i;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        n += ofs;
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            a += ofs;
            b += ofs;
            edg[a].push_back(b);
            edg[b].push_back(a);
            joint(a, b);
        }
        map<int, vector<int>> mp;
        for (int i = ofs + 1; i <= n; ++i)
            mp[find(i)].push_back(i);
        long long res = 1;

        stack<int> stk;
        for (auto g : mp)
        {
            bool fl = 0;
            for (auto a : g.second)
                stk.push(a);
            tg[stk.top()] = 1;
            while (!stk.empty() && !fl)
            {
                int a = stk.top();
                stk.pop();
                for (auto i : edg[a])
                {
                    if (find(i) != find(a))
                        continue;
                    if (tg[i] == 0)
                        stk.push(i);
                    if (tg[i] != tg[a])
                        tg[i] = -tg[a];
                    else
                    {
                        fl = 1;
                        break;
                    }
                }
            }
            if (fl)
            {
                res = 0;
                break;
            }
            long long l = 0, ts = 1;
            for (auto i : g.second)
                l = tg[i] == 1 ? l + 1 : l;
            long long r = g.second.size() - l;
            while (l--)
                ts = (ts << 1) % MOD;
            long long rts = 1;
            while (r--)
                rts = (rts << 1) % MOD;
            rts = (ts + rts) % MOD;
            res = (rts * res) % MOD;
        }
        ofs = n;
        cout << res << endl;
    }
    return 0;
}