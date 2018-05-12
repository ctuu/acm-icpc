#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
array<int, N> p, sx, d, val;
array<bool, N> vis;
int find(int x) { return p[x] == x ? x : find(p[x]); }
struct Edge
{
    int u, v, c;
};
using G = vector<Edge>;

void mst(G &gr)
{
    sx.fill(1);
    d.fill(0);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    auto pa = gr;
    sort(pa.begin(), pa.end(), [](Edge &a, Edge &b) { return a.c < b.c; });
    for (auto e : pa)
    {
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        if (sx[u] >= sx[v])
        {
            swap(u, v);
            swap(e.u, e.v);
        }
        cout << u <<" " << e.c << endl;
        d[e.u] = e.c;
        p[u] = v;
        sx[v] += sx[u];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, c, q;
    while (cin >> n >> m)
    {
        G gr;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr.push_back({u, v, c});
        }
        mst(gr);
        cout << endl;
        for(int i = 1; i<= n; ++i)
            cout << i <<" " << p[i] <<" " << d[i] << endl;
        cout << endl;
        cin >> q;
        while (q--)
        {
            vis.fill(0);
            val.fill(0);
            cin >> u >> v;
            vis[u] = 1;
            while (p[u] != u)
            {
                val[p[u]] = max(d[u], val[u]);
                u = p[u];
                vis[u] = 1;
            }
            while(!vis[v])
            {
                vis[v] = 1;
                val[p[v]] = max(d[v], val[v]);
                v = p[v];
            }
            cout << val[v] << endl;
        }
        cout << endl;
    }
    return 0;
}