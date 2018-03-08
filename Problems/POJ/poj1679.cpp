#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define P 3000
#define G vector<Edge>
int V;
int p[P];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
vector<int> me;
struct Edge
{
    int u, v, c;
    Edge(){};
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int mst(G &gr, int t)
{
    for (int i = 0; i < P; ++i)
        p[i] = i;
    int sum = 0, ct = 0;
    int tmp = gr.size();
    for (int i = 0; i < tmp; ++i)
    {
        Edge e = gr[i];
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        p[u] = v;
        ++ct;
        sum += e.c;
        if (t)
            me.push_back(i);
    }
    if (ct == V - 1)
        return sum;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, u, v, c;
        cin >> n >> m;
        V = n;
        G gr;
        me.clear();
        bool fl = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr.push_back(Edge(u, v, c));
        }
        sort(gr.begin(), gr.end(), cmp);
        int ans = mst(gr, 1);
        if (ans != 0 && m)
        {
            int si = me.size();
            for (int i = 0; i < si; ++i)
            {
                G mgr;
                for (int j = 0; j < m; ++j)
                {
                    if (me[i] != j)
                        mgr.push_back(gr[j]);
                }
                if (ans == mst(mgr, 0))
                {
                    fl = 1;
                    break;
                }
            }
        }
        if (fl)
            cout << "Not Unique!" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}