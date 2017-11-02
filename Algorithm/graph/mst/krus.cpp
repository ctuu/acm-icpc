#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define G pair<vector<Edge>, int>
const int N = 1e5;
int ct = 0;
struct Edge
{
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
    int oth(int x)
    {
        return x == u ? v : u;
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

struct UF
{
    array<int, N> p;
    UF()
    {
        for (int i = 0; i < N; ++i)
            p[i] = i;
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void joint(int a, int b)
    {
        int i = find(a);
        int j = find(b);
        p[i] = j;
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
        gr.second = n;
        int u, v, c;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr.first.push_back(Edge(u - 1, v - 1, c));
        }
        cout << mst(gr) << endl;
    }
    return 0;
}

int mst(G &gr)
{
    UF uf = UF();
    priority_queue<Edge> pq;
    int sum = 0, ct = 0;
    for (auto i : gr.first)
        pq.push(i);
    int si = gr.second;
    while (!pq.empty() && ct < si - 1)
    {
        Edge e = pq.top();
        pq.pop();
        int u = e.u;
        int v = e.oth(u);
        if (uf.find(u) == uf.find(v))
            continue;
        uf.joint(u, v);
        ++ct;
        ++sum;
    }
    return sum;
}