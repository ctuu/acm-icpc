#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define N 20005
#define G vector<vector<int>>
array<int, N> low, dfn, vis, fa, belong;
int ct = 0, cnt = 0;
stack<int> stk;
void tarjan(G &gr, int u)
{
    dfn[u] = low[u] = ++ct;
    vis[u] = 1;
    stk.push(u);
    for (auto v : gr[u])
    {
        if (!dfn[v])
        {
            fa[v] = u;
            tarjan(gr, v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v] && fa[u] != v)
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        ++cnt;
        int v;
        vector<int> tmp;
        do
        {
            v = stk.top();
            stk.pop();
            vis[v] = 0;
            tmp.push_back(v);
        } while (v != u);
        sort(tmp.begin(), tmp.end());
        for(auto i: tmp)
            belong[i] = tmp[0];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    G gr;
    gr.resize(n + 1);
    ct = cnt = 0;
    low.fill(0);
    dfn.fill(0);
    vis.fill(0);
    fa.fill(0);
    belong.fill(0);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    tarjan(gr, 1);
    cout << cnt << endl;
    for (int i = 1; i <= n; ++i)
        cout << belong[i] << " ";
    return 0;
}