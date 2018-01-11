#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 7;
int ct = 0;
array<bool, N> mrk;
array<int, N> dist;
struct Edge
{
    int v, c;
    Edge() = default;
    Edge(int v, int c) : v(v), c(c) {}
    bool operator<(const Edge &a) const { return c > a.c; }
};
using G = vector<vector<Edge>>;
int mst(G &gr, int size)
{
    int sum = 0;
    map<int, int> idx;
    dist.fill(INF);
    mrk.fill(0);
    idx[0] = 0;
    dist[0] = 0;
    while (!idx.empty())
    {
        auto iter = idx.begin();
        int u = iter->second;
        idx.erase(iter);
        mrk[u] = 1;
        for (auto e : gr[u])
        {
            int v = e.v;
            if (mrk[v])
                continue;
            if (e.c < dist[v])
            {
                dist[v] = e.c;
                idx[dist[v]] = v;
            }
        }
    }
    for (int i = 0; i < size; ++i)
        sum += dist[i];
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
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        gr[u - 1].push_back(Edge(v - 1, c));
        gr[v - 1].push_back(Edge(u - 1, c));
    }
    int ans = mst(gr, n);
    cout << ans << endl;
    return 0;
}