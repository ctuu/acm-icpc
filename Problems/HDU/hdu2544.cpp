#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using G = vector<vector<int>>; //save index
array<int, N> vis, d;
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
    int fr, to, di;
    Edge() = default;
    Edge(int u, int v, int w) : fr(u), to(v), di(w) {}
};
using E = vector<Edge>;
void dijkstra(G &gr, E &edg, int s)
{
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
    int n, m;
    while (cin >> n >> m && n && m)
    {
        G gr;
        E edg;
        gr.resize(n + 1);
        edg.resize(m + 1);
        for (int i = 0; i < m; ++i)
        {
            int fr, to, di;
            cin >> fr >> to >> di;
            edg[i] = Edge(fr, to, di);
            gr[fr].push_back(i);
            gr[to].push_back(i);// if Two-Way
        }
        for (int i = 0; i <= n; ++i)
        {
            d[i] = INF;
            vis[i] = 0;
        }
        d[1] = 0;
        dijkstra(gr, edg, 1);
        cout << d[n] << endl;
    }
    return 0;
}