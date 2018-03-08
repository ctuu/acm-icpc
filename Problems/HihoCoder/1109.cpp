#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
int ct = 0;
struct Edge
{
    int v, c;
    Edge() = default;
    Edge(int v, int c) : v(v), c(c) {}
    bool operator<(const Edge &a) const
    {
        return c > a.c;
    }
};
using G = vector<vector<Edge>>;
array<bool, N> mrk;

int mst(G &gr)
{
    int sum = 0;
    priority_queue<Edge> pq;
    mrk.fill(0);
    mrk[0] = 1;
    for (auto e : gr[0])
        pq.push(e);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        mrk[v] = 1;
        sum += e.c;
        for (auto e : gr[v])
            if (!mrk[e.v])
                pq.push(e);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, c;
    cin >> n >> m;
    G gr;
    gr.resize(n + 1);
    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        gr[u - 1].push_back(Edge(v - 1, c));
        gr[v - 1].push_back(Edge(u - 1, c));
    }
    int ans = mst(gr);
    cout << ans << endl;
    return 0;
}