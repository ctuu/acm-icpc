#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 1000
#define G pair<vector<Edge>, int>
vector<pair<int, int> > lis;
int p[N];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
struct Edge
{
    int u, v;
    int c;
    Edge(){};
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int mst(G &gr)
{
    int sum = 0;
    int ct = 0;
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
        lis.push_back(make_pair(e.u, e.v));
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int poi[760];
    int poj[760];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> poi[i] >> poj[i];
    G gr;
    for (int i = 0; i < N; ++i)
        p[i] = i;
    gr.second = n;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        p[find(y)] = find(x);
    }
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
                gr.first.push_back(Edge(i + 1, j + 1, (poi[i] - poi[j]) * (poi[i] - poi[j]) + (poj[i] - poj[j]) * (poj[i] - poj[j])));

    int ans = mst(gr);
    // cout << ans << endl;
    int si = lis.size();
    for (int i = 0; i < si; ++i)
        cout << lis[i].first << " " << lis[i].second << endl;
    return 0;
}