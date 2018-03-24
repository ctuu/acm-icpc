#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1003;
const int M = 1003;
array<array<int, N>, N> ext;
array<int, N> d1, d2;
const int INF = 0x3f3f3f3f;
using G = vector<vector<int>>; //save index
array<int, N> d;
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
void dijkstra(G &gr, E &edg, int s, array<int, N> &d)
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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    G gr;
    E edg;
    gr.resize(n + 1);
    edg.resize(m + 1);
    for (int i = 0; i < m; ++i)
    {
        int fr, to;
        cin >> fr >> to;
        ext[fr][to] = 1;
        ext[to][fr] = 1;
        edg[i] = Edge(fr, to, 1);
        gr[fr].push_back(i);
        gr[to].push_back(i);
    }
    dijkstra(gr, edg, s, d1);
    dijkstra(gr, edg, t, d2);
    int cnt = 0, mph = d1[t];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (ext[i][j] || i == j)
                continue;
            int tmp = min(d1[i] + d2[j], d1[j] + d2[i]) + 1;
            if (tmp >= mph)
            {
                ++cnt;
                ext[i][j] = ext[j][i] = 1;
            }
        }
    cout << cnt << endl;
    return 0;
}