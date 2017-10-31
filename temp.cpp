#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<pair<int, int>> G[N];
int vis[N];
int main()
{
    int T;
    int fibo[35];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 35; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    scanf("%d", &T);
    int ca = 0;
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++)
            G[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            G[x].push_back(make_pair(y, z));
            G[y].push_back(make_pair(x, z));
        }
        int ct = 1;
        int maxx = 0;
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < G[1].size(); i++)
        {
            int v = G[1][i].first, w = G[1][i].second;
            q.push(make_pair(w, v));
        }
        while (!q.empty())
        {
            int u = q.top().second, w = q.top().first;
            q.pop();
            if (vis[u])
                continue;
            maxx += w;
            ct++;
            vis[u] = 1;
            for (int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i].first, w = G[u][i].second;
                if (!vis[v])
                {
                    q.push(make_pair(w, v));
                }
            }
        }
        cout << "Case #" << ++ca << ": ";
        if (ct != n)
        {
            cout << "No" << endl;
            continue;
        }
        ct = 1;
        int minn = 0;
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        while (!q.empty())
            q.pop();
        for (int i = 0; i < G[1].size(); i++)
        {
            int v = G[1][i].first, w = G[1][i].second;
            q.push(make_pair(-w, v));
        }
        while (!q.empty())
        {
            int u = q.top().second, w = q.top().first;
            q.pop();
            if (vis[u])
                continue;
            minn -= w;
            ct++;
            vis[u] = 1;
            for (int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i].first, w = G[u][i].second;
                if (!vis[v])
                {
                    q.push(make_pair(-w, v));
                }
            }
        }
        int flag = 0;
        for (int i = 1; i < 35; i++)
        {
            if (fibo[i] >= minn && fibo[i] <= maxx)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}