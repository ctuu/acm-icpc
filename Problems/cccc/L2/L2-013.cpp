#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 20005;
using G = vector<vector<int>>;
array<int, N> dfn, low, vis, fa, lve;
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
        if(!lve[v])
            continue;
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
    int n, m, a, b, k;
    cin >> n >> m;
    lve.fill(1);
    gr.resize(n + 2);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cnt = 0;
        dfn.fill(0);
        low.fill(0);
        vis.fill(0);
        fa.fill(0);
        cin >> a;
        tarjan(gr, a);
        if (gd.count(a))
            cout << "Red Alert: ";
        cout << "City " << a << " is lost";
        gd.count(a) ? cout << "!" << endl : cout << "." << endl;
        lve[a] = 0;
        gd.clear();
    }
    for (int i = 0; i < n; ++i)
        if (lve[i])
            return 0;
    cout << "Game Over." << endl;
    return 0;
}