#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define G vector<Edge>
const int N = 1e5;
int p[N], n;
bool fl = 0;
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
    int m;
    while (cin >> n >> m && n)
    {
        for (int i = 0; i < m; ++i)
            cin >> gr[i].u >> gr[i].v >> gr[i].c;
        sort(gr, gr + n, cmp);
        cout << endl;
        for(int i = 0; i <m; ++i)
        cout << gr[i].u << " " << gr[i].v << " " << gr[i].c << endl;
        long long ans = INF;
        for (int i = 0; i < m; ++i)
        {
            for (int j = i + 1; j < m; ++j)
            {
                for (int i = 0; i < N; ++i)
                    p[i] = i;
                long long mam = 0, ct = 0;
                for (int k = i; k <= j; ++k)
                {
                    Edge e = gr[k];
                    int a = find(e.u), b = find(e.v);
                    if (a != b)
                    {
                        p[a] = b;
                        ++ct;
                        mam = max(mam, e.c);
                    }
                }
                if (ct == n - 1)
                    ans = min(ans, gr[j].c - gr[i].c);
            }
        }
        if (ans == INF)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}