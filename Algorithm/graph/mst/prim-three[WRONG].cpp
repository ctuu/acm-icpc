#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1000;
int ct = 0;
struct Edge
{
    int fr, to, di;
    Edge() = default;
    Edge(int u, int v, int w) : fr(u), to(v), di(w) {}
    bool operator<(const Edge &a) const{ return di > a.di; }
};
using G = vector<vector<Edge>>;
int mst(G &gr)
{
    int sum = 0;
    priority_queue<Edge> pq;
    array<bool, N> mrk;
    mrk.fill(0);
    mrk[0] = 1;
    for (auto e : gr[0])
        pq.push(e);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int u = e.fr, v = e.to;
        if (mrk[u] && mrk[v])
            continue;
        sum += e.di;
        if (!mrk[u])
        {
            mrk[u] = 1;
            for (auto e : gr[u])
                if (!mrk[v])
                    pq.push(e);
        }
        if (!mrk[v])
        {
            mrk[v] = 1;
            for (auto e : gr[v])
                if (!mrk[u])
                    pq.push(e);
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && n)
    {
        G gr;
        gr.resize(n);
        int u, v, c;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr[u - 1].push_back(Edge(u - 1, v - 1, c));
        }
        int ans = mst(gr);
        cout << ans << endl;
    }
    return 0;
}