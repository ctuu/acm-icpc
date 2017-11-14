#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#define INF (1LL << 62) //WA了好几发
#define ll long long int
using namespace std;

typedef pair<ll, int> P;
struct edge
{
    int to;
    ll dis;
    edge(int to, ll dis)
    {
        this->to = to;
        this->dis = dis;
    }
};
int N, R;
int a, b;
ll c;
ll dis[100005];  //记录最短路径
ll disc[100005]; //记录次短路径
vector<edge> G[100005];

void dijkstra()
{
    fill(dis, dis + 100005, INF);
    fill(disc, disc + 100005, INF);
    priority_queue<P, vector<P>, greater<P>> q;
    dis[1] = 0;
    q.push(P(0, 1));
    while (q.size())
    {
        P p = q.top();
        q.pop();
        ll dd = p.first;
        int v = p.second;
        if (disc[v] < dd)
            continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
            ll d = dd + e.dis;
            if (dis[e.to] >= d)
            {
                ll ttt = d;
                d = dis[e.to];
                dis[e.to] = ttt;
                q.push(P(dis[e.to], e.to));
            }
            if (disc[e.to] >= d && dis[e.to] <= d)
            {
                disc[e.to] = d;
                q.push(P(disc[e.to], e.to));
            }
        }
    }
    cout << disc[N] << endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        for (int i = 0; i < 100005; i++)
            G[i].clear();

        scanf("%d%d", &N, &R);
        for (int i = 1; i <= R; i++)
        {
            scanf("%d%d%lld", &a, &b, &c);
            G[a].push_back(edge(b, c));
            G[b].push_back(edge(a, c));
        }
        dijkstra();
    }
    return 0;
}