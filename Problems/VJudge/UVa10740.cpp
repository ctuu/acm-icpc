#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
using G = vector<vector<int>>; //save index
array<int, N> vis, d;
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
void dijkstra(G &gr, E &edg, int s)
{
    d.fill(INF);
    d[s] = 0;
    vis.fill(0);
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

struct Ande
{
    int u, g, f;
    Ande(int u, int g, int f) : u(u), g(g), f(f) {}
    bool operator<(const Ande a) const
    {
        if (a.f == f)
            return a.g < g;
        return a.f < f;
    }
};

int astar(G &gr, E &edg, int s, int t, int k)
{
    if (d[s] == INF)
        return INF;
    priority_queue<Ande> que;
    que.push(Ande(s, 0, d[s]));
    while (!que.empty())
    {
        Ande c = que.top();
        que.pop();
        int u = c.u;
        if (u == t)
            if (k-- <= 1)
                return c.f;
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = (e.fr == u) ? e.to : e.fr;
            que.push(Ande(to, c.g + e.di, c.g + e.di + d[to]));
        }
    }
    return INF;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, t, k;
    while (cin >> n >> m && n)
    {
        cin >> s >> t >> k;
        G gr, grr;
        E edg;
        gr.resize(n + 1);
        grr.resize(n + 1);
        edg.resize(m + 1);
        for (int i = 0; i < m; ++i)
        {
            int fr, to, di;
            cin >> fr >> to >> di;
            edg[i] = Edge(fr, to, di);
            grr[to].push_back(i); // 反向建图
            gr[fr].push_back(i);
            // gr[to].push_back(i);// if Two-Way
        }
        dijkstra(grr, edg, t);
        int ans = astar(gr, edg, s, t, k);
        ans = (ans == INF) ? -1 : ans;
        cout << ans << endl;
    }
    return 0;
}