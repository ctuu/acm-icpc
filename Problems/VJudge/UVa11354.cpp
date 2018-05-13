#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
array<int, N> p, sx, d, val;
int find(int x) { return p[x] == x ? x : find(p[x]); }
struct Edge
{
    int u, v, c;
};
using G = vector<Edge>;

void mst(G &gr)
{
    sx.fill(0);
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
        if (sx[u] < sx[v])
        {
            p[u] = v;
            d[u] = e.c;
        }
        else
        {
            p[v] = u;
            d[v] = e.c;
            if (sx[u] == sx[v])
                sx[u]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, c, q;
    int wtf = 0;
    while (cin >> n >> m)
    {
        if (wtf)
            cout << endl;
        wtf = 1;
        G gr;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr.push_back({u, v, c});
        }
        mst(gr);
        val.fill(-1);
        cin >> q;
        while (q--)
        {
            cin >> u >> v;
            int cr = u;
            val[u] = 0;
            while (u != p[u])
            {
                val[p[u]] = max(val[u], d[u]);
                u = p[u];
            }
            int mx = -1;
            while (val[v] < 0 && v != p[v])
            {
                mx = max(mx, d[v]);
                v = p[v];
            }
            cout << max(mx, val[v]) << endl;
            u = cr;
            val[u] = -1;
            while (u != p[u])
            {
                val[p[u]] = -1;
                u = p[u];
            }
        }
    }
    return 0;
}