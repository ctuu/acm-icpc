#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define G pair<vector<Edge>, int>
const int N = 1e5;
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
struct Edge
{
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int mst(G &gr);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
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
    int sum = 0, ct = 0;
    vector<Edge> pa = gr.first;
    sort(pa.begin(), pa.end(), [](Edge &a, Edge &b) { return a.c < b.c; });
    int si = pa.size();
    for (int i = 0; i < si; ++i)
    {
        Edge e = pa[i];
        int u = e.u, v = e.v;
        if (uf.find(u) == uf.find(v))
            continue;
        uf.joint(u, v);
        ++ct;
        sum += e.c;
    }
    return sum;
}