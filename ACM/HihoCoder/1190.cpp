#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define N 20000
using G = vector<vector<int>>;
array<int, N> dfn, low, belong;
array<int, 100005> ans;
vector<pair<int, int>> edges;
stack<int> stk;
int cnt, ct;
void tarjan(G &gr, int u, int fa)
{
    dfn[u] = low[u] = ++cnt;
    for (auto k : gr[u])
    {
        int v = (u == edges[k].first) ? edges[k].second : edges[k].first;
        if (v == fa)
            continue;
        if (!dfn[v])
        {
            stk.push(k);
            tarjan(gr, v, u);
            low[u] = min(low[v], low[u]);
            if (low[v] >= dfn[u])
            {
                ++ct;
                int e, mim = 100006;
                do
                {
                    e = stk.top();
                    stk.pop();
                    belong[e] = ct;
                    mim = min(mim, e);
                } while (e != k);
                ans[ct] = mim;
            }
        }
        else if (dfn[v] < dfn[u])
        {
            stk.push(k);
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    dfn.fill(0);
    low.fill(0);
    belong.fill(0);
    ans.fill(0);
    ct = cnt = 0;
    G gr;
    gr.resize(n + 1);
    edges.push_back(make_pair(0, 0));
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        edges.push_back(make_pair(a, b));
        gr[a].push_back(i);
        gr[b].push_back(i);
    }
    tarjan(gr, 1, -1);
    cout << ct << endl;
    for (int i = 1; i <= m; ++i)
        cout << ans[belong[i]] << " ";
    cout << endl;
    return 0;
}