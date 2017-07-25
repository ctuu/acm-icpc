//Copyright 2017 Parallelc
#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using T =int;
const T INF = 0x3f3f3f3f;
struct edge {
    int v, w;
    bool operator < (const edge & e) const {return w > e.w;}
};
vector<int> jy;
vector<int> dp;
vector<int> pre;
void dfs(int k, int S)
{
    if (pre[k] != -1)
        dfs(pre[k], S);
    if (k != S)
        cout << k << " ";
        else cout << k;
}
T dij(const vector<vector<edge>> & lj, int S, int N)
{
    vector<int> us(lj.size()), ts(lj.size());
    int n = lj.size() -1;
    pre.resize(n + 1);
    vector<int> a(n + 1, INF);
    priority_queue<edge> q;
    q.push({S, 0});
    dp[S] = jy[S];
    ts[S] = 1;
    edge mini{0, 0};
}
