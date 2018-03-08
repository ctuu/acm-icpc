#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 2003
#define G pair<vector<Edge>, int>
char ty[2003][8];
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
int dis(int a, int b)
{
    int sum = 0;
    for (int i = 0; i < 7; ++i)
        sum += (ty[a][i] != ty[b][i]);
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n)
    {
        G gr;
        gr.second = n;
        for (int i = 0; i < n; ++i)
            cin >> ty[i];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                gr.first.push_back(Edge(i, j, dis(i, j)));
        int ans = mst(gr);
        cout << "The highest possible quality is 1/" << ans << "." << endl;
    }
    return 0;
}