#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 2e5 + 7;
const int M = 2e5 + 7;
const int INF = 0x3f3f3f3f;
using G = vector<vector<int>>; //save index
array<int, M> vis;
int ans = 0;
struct Edge
{
    int fr, to;
    Edge() = default;
    Edge(int u, int v) : fr(u), to(v) {}
};
using E = vector<Edge>;

void dfs(G &gr, E &edg, int u, int s, int la, int ct)
{
    if (gr[u].size() > 2)
        return;
    if (u == s && ct > 2)
    {
        ans++;
        return;
    }
    for (auto i : gr[u])
    {
        Edge &e = edg[i];
        int to = (e.fr == u) ? e.to : e.fr;
        if (vis[i])
        {
            if (to == la)
                continue;
            else
                return;
        }

        vis[i] = 1;
        dfs(gr, edg, to, s, u, ct + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    G gr;
    E edg;
    vis.fill(0);
    gr.resize(n + 1);
    edg.resize(m + 1);
    for (int i = 0; i < m; ++i)
    {
        int fr, to;
        cin >> fr >> to;
        edg[i] = Edge(fr, to);
        gr[fr].push_back(i);
        gr[to].push_back(i); // if Two-Way
    }
    for (int i = 1; i <= n; ++i)
    {
        if (gr[i].size() > 2)
            continue;
        dfs(gr, edg, i, i, -1, 1);
    }
    cout << ans << endl;
    return 0;
}