#include <iostream>
#include <algorithm>
#include <cstdio>
#define inf 0x7fffffff
using namespace std;
int n, p, c[10001], ft[10001], ans = inf, tot;
struct data
{
    int x, y, v;
} e[100001];
bool cmp(data a, data b)
{
    return a.v < b.v;
}
int find(int x) { return x == ft[x] ? x : ft[x] = find(ft[x]); }
int main()
{
        scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
	       scanf("%d", &c[i]);
	       ans = min(ans, c[i]);
	       ft[i] = i;
    }
    for (int i = 1; i <= p; i++)
    
    {
	     int u, v, w;
	     scanf("%d%d%d", &u, &v, &w);
	     w = (w << 1) + c[u] + c[v];
	        e[i].x = u;
	e[i].y = v;
	e[i].v = w;
    }
    sort(e + 1, e + p + 1, cmp);
    for (int i = 1; i <= p; i++)
    {
		int p = find(e[i].x), q = find(e[i].y);
		if (p != q)
		{
			ft[p] = q;
			tot++;
			ans += e[i].v;
		}
		if (tot == n - 1)
			break;
    }
    printf("%d", ans);
    return 0;
}