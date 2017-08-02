#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <ctime>
#include <climits>
using namespace std;
#define N 500005
#define M 2000005
int id(int l, int r)
{
    return l + r | l != r;
}
#define MID int mid = (l + r) >> 1;
#define ID id(l, r)
#define Left l, mid
#define Right mid + 1, r
#define LL child[p][0]
#define RR child[p][1]
struct Functional_stree
{
    int nodecnt;
    int root[N];
    int child[M][2], sum[M];
    void clear()
    {
        nodecnt = 0;
        root[0] = child[0][0] = child[0][1] = sum[0] = 0;
    }
    int newnode()
    {
        child[++nodecnt][0] = child[nodecnt][1] = 0;
        sum[nodecnt] = 0;
        return nodecnt;
    }
    void insert(int p, int q, int l, int r, int x)
    {
        if (l == r)
        {
            ++sum[p];
            return;
        }
        MID;
        if (x <= mid)
        {
            LL = newnode(), RR = child[q][1], sum[LL] = sum[child[q][0]];
            insert(LL, child[q][0], Left, x);
        }
        if (x > mid)
        {
            RR = newnode(), LL = child[q][0], sum[RR] = sum[child[q][1]];
            insert(RR, child[q][1], Right, x);
        }
        sum[p] = sum[LL] + sum[RR];
    }
    int Query(int p, int q, int l, int r, int k)
    {
        if (l == r)
            return l;
        MID;
        if (sum[LL] - sum[child[q][0]] >= k)
            return Query(LL, child[q][0], Left, k);
        return Query(RR, child[q][1], Right, k - sum[LL] + sum[child[q][0]]);
    }
};

Functional_stree t;
int n, a[N], d[N], m, Q;

void work()
{
    int i, x, y, k;
    scanf("%d%d", &m, &k);
    t.clear();
    for (i = 1; i <= m; ++i)
        scanf("%d", &a[i]), d[i] = a[i];
    sort(d + 1, d + m + 1);
    n = unique(d + 1, d + m + 1) - d - 1;
    for (i = 1; i <= m; ++i)
        a[i] = lower_bound(d + 1, d + n + 1, a[i]) - d;
    for (i = 1; i <= m; ++i)
    {
        t.root[i] = t.newnode();
        t.insert(t.root[i], t.root[i - 1], 1, n, a[i]);
    }
    long long ans = 0;
    for (int x = 1; x <= m; ++x)
        for (int y = x; y <= m; ++y)
        {
            if (y - x + 1 < k)
                continue;
            ans += d[t.Query(t.root[y], t.root[x - 1], 1, n, k)];
        }
    printf("%lld\n", ans);
    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
}

int main()
{
    int _;
    cin >> _;
    while (_--)
        work();
    return 0;
}