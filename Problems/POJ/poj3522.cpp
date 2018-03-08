#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define G vector<Edge>
const int N = 5005;
int p[N], n, m;
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
struct Edge
{
    int u, v;
    long long c;
} gr[N];
bool cmp(Edge &a, Edge &b) { return a.c < b.c; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n >> m && n)
    {
        for (int i = 0; i < m; ++i)
            cin >> gr[i].u >> gr[i].v >> gr[i].c;
        sort(gr, gr + m, cmp);
        long long ans = INF;
        int beg = 0, ct = 0;
        for (int j = 0; j < m; ++j, ct = 0)
        {
            for (int i = 0; i < N; ++i)
                p[i] = i;
            for (int i = beg; i <= j; ++i)
            {
                Edge e = gr[i];
                int a = find(e.u), b = find(e.v);
                if (a != b)
                {
                    p[a] = b;
                    ++ct;
                }
            }
            if (ct == n - 1)
            {
                ans = min(ans, gr[j].c - gr[beg].c);
                beg++;
                --j;
            }
        }
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}