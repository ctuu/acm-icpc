#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
#define N 20005
#define G vector<vector<int>>
using namespace std;
array<int, N> dfn, low, vis, fa;
set<int> gd;
vector<pair<int, int>> gb;
int cnt = 0;
void tarjan(G &gr, int u)
{
    dfn[u] = low[u] = ++cnt;
    vis[u] = 1;
    int child = 0;
    for (auto v : gr[u])
    {
        if (!dfn[v])
        {
            ++child;
            fa[v] = u;
            tarjan(gr, v);
            low[u] = min(low[u], low[v]);
            if (fa[u] == 0 && child > 1)
                gd.insert(u);
            if (fa[u] && low[v] >= dfn[u])
                gd.insert(u);
            if (low[v] > dfn[u])
                gb.push_back(make_pair(min(u, v), max(u, v)));
        }
        else if (vis[v] && fa[u] != v)
            low[u] = min(low[u], dfn[v]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G gr;
    int n, m, a, b;
    cin >> n >> m;
    cnt = 0;
    dfn.fill(0);
    low.fill(0);
    vis.fill(0);
    fa.fill(0);
    gr.resize(n + 2);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    tarjan(gr, 1);
    if (!gd.size())
        cout << "Null";
    else
        for (auto i : gd)
            cout << i << " ";
    cout << endl;
    sort(gb.begin(), gb.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });
    for (auto i : gb)
        cout << i.first << " " << i.second << endl;
    return 0;
}