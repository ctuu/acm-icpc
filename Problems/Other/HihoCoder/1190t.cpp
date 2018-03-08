#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dfn[N] = {0}, low[N] = {0}, tot = 0, belong[N], num[N], ct = 0;
vector<pair<int, int>> G[N];
stack<int> s;
void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tot;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first, id = G[u][i].second;
        if (v == fa)
            continue;
        if (!dfn[v])
        {
            s.push(id);
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                int minn = N;
                ct++;
                while (1)
                {
                    int t = s.top();
                    s.pop();
                    belong[t] = ct;
                    minn = min(t, minn);
                    if (t == id)
                        break;
                }
                num[ct] = minn;
            }
        }
        else if (dfn[v] < dfn[u])
        {
            s.push(id);
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(make_pair(y, i + 1));
        G[y].push_back(make_pair(x, i + 1));
    }
    tarjan(1, -1);
    cout << ct << endl;
    for (int i = 1; i <= m; i++)
    {
        int v = belong[i];
        cout << num[v] << ' ';
    }
    cout << endl;
    return 0;
}