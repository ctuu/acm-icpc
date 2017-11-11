#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define MN 100010
using namespace std;
#define G vector<vector<Edge>>
int ct = 0;
struct Edge
{
    int v, c;
    Edge() = default;
    Edge(int v, int c) : v(v), c(c) {}
    friend bool operator>(const Edge &a, const Edge &b)
    {
        return a.c > b.c;
    }
    friend bool operator<(const Edge &a, const Edge &b)
    {
        return a.c < b.c;
    }
};
int mst(G &gr);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> m;
        G gr;
        gr.resize(n);
        int u, v;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr[u - 1].push_back(Edge(v - 1, c));
            gr[v - 1].push_back(Edge(u - 1, c));
        }       
        mst(gr);
    }
    return 0;
}

int mst(G &gr)
{
    int sum = 0;
    priority_queue<Edge> pq;
    array<bool, MN> mrk;
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
        sum += e.c;
        mrk[v] = 1;
        for (auto e : gr[v])
            if (!mrk[e.v])
                pq.push(e);
    }
    return sum;
}