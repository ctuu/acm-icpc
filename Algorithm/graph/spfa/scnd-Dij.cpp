#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e6 + 7;
const int M = 1e6 + 7;
using LL = long long;
const LL INF = (LL)1 << 62;
using G = vector<vector<int>>; //save index
array<LL, N> d, cd;
array<int, M> pth;
struct Node
{
    LL d;
    int u;
    Node(LL d, int u) : d(d), u(u) {}
    bool operator<(const Node &a) const { return d > a.d; }
};
struct Edge
{
    int fr, to;
    LL di;
    Edge() = default;
    Edge(int u, int v, LL w) : fr(u), to(v), di(w) {}
};
using E = vector<Edge>;
void dijkstra(G &gr, E &edg, int s)
{
    d.fill(INF);
    cd.fill(INF);
    d[s] = 0;
    priority_queue<Node> pq;
    pq.push(Node(0, s));
    while (!pq.empty())
    {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (cd[u] < x.d)
            continue;
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = (e.fr == u) ? e.to : e.fr;
            LL tc = x.d + e.di;
            if (d[to] >= tc)
            {
                swap(tc, d[to]);
                pth[to] = i;
                pq.push(Node(d[to], to));
            }
            if (cd[to] >= tc && d[to] <= tc)
            {
                cd[to] = tc;
                pq.push(Node(cd[to], to));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        G gr;
        E edg;
        gr.resize(n + 1);
        edg.resize(m + 1);
        for (int i = 0; i < m; ++i)
        {
            int fr, to;
            LL di;
            cin >> fr >> to >> di;
            edg[i] = Edge(fr, to, di);
            gr[fr].push_back(i);
            gr[to].push_back(i); // Two-Way
        }
        int s = 1, t = n;
        dijkstra(gr, edg, s);
        cout << cd[t] << endl;
    }
    return 0;
}