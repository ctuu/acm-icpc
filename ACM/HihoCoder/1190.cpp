#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define N 20000
#define M 100006
using G = vector<vector<pair<int, int>>>;
array<int, N + 3> dfn, low, belong;
array<int, M> ans;
stack<int> stk;
int tot, ct;
void tarjan(G &gr, int u, int fa)
{
    dfn[u] = low[u] = ++tot;
    for (auto k : gr[u])
    {
        int v = k.first, id = k.second;
        if (v == fa)
            continue;
        if (!dfn[v])
        {
            stk.push(id);
            tarjan(gr, v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                ++ct;
                int e, mim = M;
                do
                {
                    e = stk.top();
                    stk.pop();
                    belong[e] = ct;
                    mim = min(mim, e);
                } while (e != id);
                ans[ct] = mim;
            }
        }
        else if (dfn[v] < dfn[u])
        {
            stk.push(id);
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
    ct = tot = 0;
    G gr;
    gr.resize(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        gr[a].push_back(make_pair(b, i));
        gr[b].push_back(make_pair(a, i));
    }
    tarjan(gr, 1, -1);
    cout << ct << endl;
    for (int i = 1; i <= m; ++i)
        cout << ans[belong[i]] << " ";
    cout << endl;
    return 0;
}