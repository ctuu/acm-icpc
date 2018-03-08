#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MN 1000
#define G vector<vector<Edge>>
int ct = 0;
struct Edge
{
    int v, c;
    Edge() = default;
    Edge(int v, int c)
    {
        this->v = v;
        this->c = c;
    }
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
    int n, m;
    while (cin >> m >> n && m)
    {
        G gr;
        gr.resize(n);
        int u, v, c;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr[u - 1].push_back(Edge(v - 1, c));
            gr[v - 1].push_back(Edge(u - 1, c));
        }
        ct = 1;
        int ans = mst(gr);
        // cout << ct << endl;
        if (ct == n)
            cout << ans << endl;
        else
            cout << "?" << endl;
    }
    return 0;
}

int mst(G &gr)
{
    int sum = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
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
        if (!mrk[v])
        {
            ++ct;
            mrk[v] = 1;
            for (auto e : gr[v])
                if (!mrk[e.v])
                    pq.push(e);
        }
    }
    return sum;
}