#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define N 20000
#define G vector<vector<int>>
array<int, N + 5> dfn, low, vis, belong, val, tval;
stack<int> stk;
int ct, cnt;
void tarjan(G &gr, int u)
{
    dfn[u] = low[u] = ++cnt;
    vis[u] = 1;
    stk.push(u);
    for (auto v : gr[u])
    {
        if (!dfn[v])
        {
            tarjan(gr, v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++ct;
        int v;
        do
        {
            v = stk.top();
            stk.pop();
            belong[v] = ct;
            vis[v] = 0;
            tval[ct] += val[v];
        } while (v != u);
    }
}
int dfs(vector<set<int>> &gt, int u)
{
    int ans = 0;
    for (auto i : gt[u])
        ans = max(ans, dfs(gt, i));
    return ans + tval[u];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ct = cnt = 0;
    dfn.fill(0);
    low.fill(0);
    vis.fill(0);
    belong.fill(0);
    val.fill(0);
    tval.fill(0);
    int n, m, a, b;
    cin >> n >> m;
    G gr;
    gr.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        gr[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(gr, i);
    vector<set<int>> gt;
    gt.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (auto j : gr[i])
        {
            int u = belong[i];
            int v = belong[j];
            if (u != v)
                gt[u].insert(v);
        }
    }
    int ans = dfs(gt, belong[1]);
    cout << ans << endl;
    return 0;
}