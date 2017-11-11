#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MN = 100010;
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
array<int, MN> mrk;
int ct = 0;
using G = vector<vector<Edge>>;
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
    int n, tmp;
    cin >> n;
    G gr;
    gr.resize(n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            cin >> tmp;
            gr[i].push_back(Edge(j, tmp));
        }
    int ans = mst(gr);
    cout << ans << endl;
    return 0;
}