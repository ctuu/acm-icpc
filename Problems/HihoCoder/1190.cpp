#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define N 20000
#define M 100005
using G = vector<vector<int>>;
array<int, N + 5> dfn, low, fa;
array<int, M> belong, ans;
vector<pair<int, int>> edges;
stack<int> stk;
int cnt, ct;
void tarjan(G &gr, int u)
{
    dfn[u] = low[u] = ++cnt;
    for (auto k : gr[u])
    {
        int v = (u == edges[k].first) ? edges[k].second : edges[k].first;
        if(v == fa[u]) continue;
        if (!dfn[v])
        {
            fa[v] = u;
            stk.push(k);
            tarjan(gr, v);
            low[u] = min(low[v], low[u]);
            if (low[v] >= dfn[u])
            {
                ++ct;
                ans[ct] = M;
                int e;
                do
                {
                    e = stk.top();
                    stk.pop();
                    belong[e] = ct;
                    ans[ct] = min(ans[ct], e);
                } while (e != k);
            }
        }
        else if (dfn[v] < dfn[u])
        {
            low[u] = min(low[u], dfn[v]);
            stk.push(k);
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
    fa.fill(0);
    ct = cnt = 0;
    G gr;
    gr.resize(n + 1);
    edges.resize(m + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        edges[i] = make_pair(a, b);
        gr[a].push_back(i);
        gr[b].push_back(i);
    }
    tarjan(gr, 1);
    cout << ct << endl;
    for (int i = 1; i <= m; ++i)
        cout << ans[belong[i]] << " ";
    cout << endl;
    return 0;
}