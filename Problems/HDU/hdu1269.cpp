#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
#define G vector<vector<int>>
#define MN 10005
using namespace std;
array<int, MN> dfn, low, belong;
array<bool, MN> vis;
stack<int> st;
int ct = 0, cnt;
void tarjan(G &gr, int u)
{
    dfn[u] = low[u] = ++ct;
    vis[u] = 1;
    st.push(u);
    for (auto v : gr[u])
    {
        if (!dfn[v])
        {
            tarjan(gr, v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        ++cnt;
        int v;
        do
        {
            v = st.top();
            st.pop();
            vis[v] = 0;
            belong[v] = cnt;
        } while (v != u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        G gr;
        gr.resize(n + 1);
        int a, b;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            gr[a].push_back(b);
        }
        dfn.fill(0);
        low.fill(0);
        belong.fill(0);
        ct = cnt = 0;
        tarjan(gr, 1);
        bool fl = 1;
        for (int i = 1; i <= n; ++i)
            if (belong[i] != cnt)
                fl = 0;
        if (fl)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}