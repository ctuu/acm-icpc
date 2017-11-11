#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define LL long long

int p[5005];
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
struct Edge
{
    int u, v;
    LL c;
    Edge() = default;
    Edge(int u, int v, LL c) : u(u), v(v), c(c) {}
};
using G = vector<Edge>;
bool cmp(Edge &a, Edge &b)
{
    return a.c < b.c;
}
LL dist(pair<LL, LL> &a, pair<LL, LL> &b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, q, a, b, c;
        cin >> n >> q;
        vector<LL> ql[12];
        int cost[12];
        for (int i = 0; i < q; ++i)
        {
            cin >> a >> cost[i];
            for (int j = 0; j < a; ++j)
            {
                cin >> c;
                ql[i].push_back(c);
            }
        }
        G gro;
        pair<LL, LL> po[1005];
        for (int i = 1; i <= n; ++i)
        {
            cin >> a >> b;
            po[i] = make_pair(a, b);
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                gro.push_back(Edge(i, j, dist(po[i], po[j])));
        sort(gro.begin(), gro.end(), cmp);
        G gr;
        int ct = 0;
        for (int i = 0; i < 1005; ++i)
            p[i] = i;
        int si = gro.size();
        for (int i = 0; i < si && ct < si - 1; ++i)
        {
            Edge e = gro[i];
            a = find(e.u), b = find(e.v);
            if (a != b)
            {
                p[a] = b;
                ++ct;
                gr.push_back(e);
            }
        }
        LL ans = INF;
        for (int i = 0; i < (1 << q); ++i)
        {
            G grt = gr;
            LL sum = 0;
            for (int j = 0; j < q; ++j)
                if (i & (1 << j))
                {
                    sum += cost[j];
                    int si = ql[j].size();
                    for (int k = 1; k < si; ++k)
                        grt.push_back(Edge(ql[j][k - 1], ql[j][k], 0));
                }
            sort(grt.begin(), grt.end(), cmp);
            ct = 0;
            int si = grt.size();
            for (int j = 0; j < 1005; ++j)
                p[j] = j;
            for (int j = 0; j < si && ct < n - 1; ++j)
            {
                Edge e = grt[j];
                a = find(e.u), b = find(e.v);
                if (a != b)
                {
                    p[a] = b;
                    ++ct;
                    sum += e.c;
                }
            }
            ans = min(ans, sum);
        }
        cout << ans << endl;
        if (T)
            cout << endl;
    }
    // b = gr.size();
    // for (int i = 0; i < b; ++i)
    //     cout << gr[i].u << " " << gr[i].v << "  " << gr[i].c << endl;
    return 0;
}
