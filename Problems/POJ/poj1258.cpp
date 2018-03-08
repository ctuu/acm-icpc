#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 3000
#define G pair<vector<Edge>, int>
int p[N];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
struct Edge
{
    int u, v, c;
    Edge(){};
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int mst(G &gr)
{
    for (int i = 0; i < N; ++i)
        p[i] = i;
    int sum = 0, ct = 0;
    vector<Edge> pa = gr.first;
    sort(pa.begin(), pa.end(), cmp);
    int tmp = pa.size();
    for (int i = 0; i < tmp; ++i)
    {
        Edge e = pa[i];
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        p[u] = v;
        ++ct;
        sum += e.c;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    while (cin >> n)
    {
        G gr;
        gr.second = n;
        for (int i = 0; i < N; ++i)
            p[i] = i;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> c;
                if (i < j)
                    gr.first.push_back(Edge(i + 1, j + 1, c));
            }
        int ans = mst(gr);
        cout << ans << endl;
    }
    return 0;
}