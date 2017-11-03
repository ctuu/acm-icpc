#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define G vector<Edge>
const int N = 1e5;
int p[N], n;
bool fl = 0;
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
struct Edge
{
    int u, v;
    long long c;
} gr[N];
bool cmp(Edge &a, Edge &b) { return a.c < b.c; }
long long mst(G &gr);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    while (cin >> n >> m && n)
    {
        for (int i = 0; i < m; ++i)
            cin >> gr[i].u >> gr[i].v >> gr[i].c;
        sort(gr, gr + m, cmp);
        long long ans = INF;
        vector<Edge> g;
        for (int j = 0; j < m; ++j)
        {
            g.push_back(gr[j]);
            long long tmp = mst(g);
            while (fl)
            {
                ans = min(ans, tmp);
                fl = 0;
                g.erase(g.begin());
                tmp = mst(g);
            }
        }
        if (ans == INF)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}

long long mst(G &gr)
{
    for (int i = 0; i < N; ++i)
        p[i] = i;
    int si = gr.size(), ct = 0;
    for (int i = 0; i < si; ++i)
    {
        Edge e = gr[i];
        int a = find(e.u), b = find(e.v);
        if (a != b)
        {
            p[a] = b;
            ++ct;
        }
    }
    if (ct == n - 1)
        fl = 1;
    return gr[si - 1].c - gr[0].c;
}