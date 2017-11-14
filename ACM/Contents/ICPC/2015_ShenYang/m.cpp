#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 3e6 + 7;
const int M = N;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using G = vector<vector<int>>;
array<int, N> d1, d2;
array<bool, N> vis;
array<int, M> pth;
struct Node
{
    int d, u;
    Node(int d, int u) : d(d), u(u) {}
    bool operator<(const Node &a) const
    {
        return d > a.d;
    }
};
struct Edge
{
    int fr, to;
    int di;
    Edge() = default;
    Edge(int u, int v, int w) : fr(u), to(v), di(w) {}
};
using E = vector<Edge>;
void dijkstra(G &gr, E &edg, int s, array<int, N> &d)
{
    priority_queue<Node> pq;
    pq.push(Node(0, s));
    while (!pq.empty())
    {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = (e.fr == u) ? e.to : e.fr;
            if (d[to] > d[u] + e.di)
            {
                d[to] = d[u] + e.di;
                pth[to] = i;
                pq.push(Node(d[to], to));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt)
    {
        int n, m;
        cin >> n >> m;
        G gr;
        E edg;
        gr.resize(N);
        edg.resize(N);
        int t;
        int s, tmp, ind = 2e6 + 2, ct = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> t >> s;
            edg[ind] = Edge(ind, ind + 1, t);
            gr[ind].push_back(ind);
            for (int j = 0; j < s; ++j)
            {
                cin >> tmp;
                edg[ct] = Edge(tmp, ind, 0);
                gr[tmp].push_back(ct);
                edg[ct + 1] = Edge(ind + 1, tmp, 0);
                gr[ind + 1].push_back(ct + 1);
                ct += 2;
            }
            ind += 2;
        }
        d1.fill(INF);
        vis.fill(0);
        d1[1] = 0;
        dijkstra(gr, edg, 1, d1);
        d2.fill(INF);
        vis.fill(0);
        d2[n] = 0;
        dijkstra(gr, edg, n, d2);
        int mim = INF;
        for (int i = 1; i <= n; ++i)
            mim = min(mim, max(d1[i], d2[i]));
        cout << "Case #" << tt << ": ";
        bool fl = 0;
        if (mim != INF)
        {
            cout << mim << endl;
            for (int i = 1; i <= n; ++i)
            {
                if (max(d1[i], d2[i]) == mim)
                {
                    if (fl)
                        cout << " ";
                    cout << i;
                    fl = 1;
                }
            }
            cout << endl;
        }
        else
            cout << "Evil John" << endl;
    }
    return 0;
}