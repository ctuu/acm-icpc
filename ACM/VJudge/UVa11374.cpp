#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using G = vector<vector<int>>; //save index
array<int, N> vis, db, de;
array<int, M> pthb, pthe;
struct Node
{
    int d, u;
    Node(int d, int u) : d(d), u(u) {}
    bool operator<(const Node &a) const
    {
        return d > a.d;
    }
};
struct Edge
{
    int fr, to, di;
    Edge(int u, int v, int w) : fr(u), to(v), di(w) {}
};
using E = vector<Edge>;
void dijkstra(G &gr, E &edg, int s, array<int, N> &d, array<int, M> &pth)
{
    priority_queue<Node> pq;
    pq.push(Node(0, s));
    for (int i = 0; i < N; ++i)
    {
        vis[i] = 0;
        pth[i] = 0;
    }
    while (!pq.empty())
    {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = (e.fr == u) ? e.to : e.fr;
            if (d[to] > d[u] + e.di)
            {
                d[to] = d[u] + e.di;
                pth[to] = i;
                pq.push(Node(d[to], to));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, e, k;
    while (cin >> n >> s >> e)
    {
        G gr;
        E edg, exp;
        gr.resize(n + 1);
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int fr, to, di;
            cin >> fr >> to >> di;
            edg.push_back(Edge(fr, to, di));
            gr[fr].push_back(i);
            gr[to].push_back(i); // if Two-Way
        }
        cin >> k;
        for (int i = 0; i < k; ++i)
        {
            int fr, to, di;
            cin >> fr >> to >> di;
            exp.push_back(Edge(fr, to, di));
        }
        for (int i = 0; i <= n; ++i)
        {
            de[i] = INF;
            db[i] = INF;
        }
        db[s] = 0;
        de[e] = 0;
        dijkstra(gr, edg, s, db, pthb);
        dijkstra(gr, edg, e, de, pthe);
        int ans = db[e], ind = 0;
        for (int i = 0; i < k; ++i)
        {
            Edge &e = exp[i];
            int pth = min(de[e.fr] + db[e.to], db[e.fr] + de[e.to]) + e.di;
            if (ans > pth)
            {
                ans = pth;
                ind = i + 1;
            }
            ans = min(ans, pth);
        }
        if (ind)
        {
            Edge eg = exp[ind - 1];
            int u = (de[eg.fr] + db[eg.to] > db[eg.fr] + de[eg.to]) ? eg.fr : eg.to; //beg to beg
            int tk = u;
            int v = (u == eg.fr) ? eg.to : eg.fr; // end to end
            stack<int> stk;
            stk.push(u);
            do
            {
                eg = edg[pthb[u]];
                u = (eg.to == u) ? eg.fr : u;
                stk.push(u);
            } while (u != s);
            vector<int> p;
            do
            {
                eg = edg[pthe[v]];
                v = (eg.to == v) ? eg.fr : v;
                p.push_back(v);
            } while (v != e);
            while (!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            for (auto i : p)
                cout << i << " ";
            cout << endl;
            cout << tk << endl;
        }
        if (!ind)
        {
            stack<int> stk;
            int u = e;
            stk.push(u);
            do
            {
                Edge eg = edg[pthb[u]];
                u = (eg.to == u) ? eg.fr : u;
                stk.push(u);
                // cout << "!!!" << endl;
            } while (u != s);
            while (!stk.empty())
            while (!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            cout << endl;
            cout << "Ticket Not Used" << endl;
        }
        cout << ans << endl;
    }
    return 0;
}