#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define MP(a, b) make_pair(a, b)
const int N = 10003;
using PII = pair<int, int>;
using G = vector<set<int>>;
array<bool, N> vis;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G gr;
    int n, m, k;
    cin >> n >> m >> k;
    gr.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        gr[a].insert(b);
        gr[b].insert(a);
    }
    for (int i = 0; i < k; ++i)
    {
        vis.fill(0);
        int t;
        cin >> t;
        PII ans = MP(t, 0);
        vis[t] = 1;
        queue<PII> qu;
        for (auto i : gr[t])
        {
            qu.push(MP(i, 1));
            vis[i] = 1;
        }
        while (!qu.empty())
        {
            auto cu = qu.front();
            qu.pop();
            if (ans.second < cu.second)
                ans = cu;
            else if (ans.second == cu.second && ans.first > cu.first)
                ans = cu;
            for (auto i : gr[cu.first])
                if (!vis[i])
                {
                    qu.push(MP(i, cu.second + 1));
                    vis[i] = 1;
                }
        }
        ans.first = ans.second == 0 ? 0 : ans.first;
        cout << ans.first << endl;
    }
    return 0;
}