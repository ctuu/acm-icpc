#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
using G = vector<vector<int>>;
array<int, N> d, phs;
array<int, M> pth;
struct Node
{
    int d, u;
    Node(int d, int u) : d(d), u(u) {}
    bool operator<(const Node &a) const { return d > a.d; }
};
struct Edge
{
    int fr, to, di;
    Edge() = default;
    Edge(int u, int v, int w) : fr(u), to(v), di(w) {}
};
using E = vector<Edge>;
array<int, N> bd, res;
int cnt;
void dijkstra(G &gr, E &edg, int s)
{
    d.fill(INF);
    d[s] = 0;
    priority_queue<Node> pq;
    pq.push(Node(0, s));
    while (!pq.empty())
    {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (d[u] < x.d)
            continue;
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = (e.fr == u) ? e.to : e.fr;
            int b = d[u] + e.di;
            int c = res[u] + bd[to];
            if (d[to] == b)
            {
                // res[to] = max(res[to], res[u] + bd[to]);
                if (res[to] < c)
                {
                    res[to] = c;
                    pth[to] = i;
                }
                phs[to] += phs[u];
            }
            else if (d[to] > b)
            {
                phs[to] = phs[u];
                pth[to] = i;
                res[to] = c;
                d[to] = b;
                pq.push(Node(d[to], to));
            }
        }
    }
}
void out(E &edg, int s, int t)
{
    int i = pth[t];
    auto &e = edg[i];
    int j = e.fr == t ? e.to : e.fr;
    if (j != s)
        out(edg, s, j);
    else
        cout << s;
    cout << " " << t;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    G gr;
    E edg;
    cnt = 1;
    gr.resize(n + 10);
    edg.resize(m + 10);
    res.fill(0);
    phs.fill(0);
    for (int i = 0; i < n; ++i)
        cin >> bd[i];
    for (int i = 0; i < m; ++i)
    {
        int fr, to, di;
        cin >> fr >> to >> di;
        edg[i] = Edge(fr, to, di);
        gr[fr].push_back(i);
        gr[to].push_back(i);
    }
    res[s] = bd[s];
    phs[s] = 1;
    dijkstra(gr, edg, s);
    cout << phs[t] << " " << res[t] << endl;
    out(edg, s, t);
    return 0;
}