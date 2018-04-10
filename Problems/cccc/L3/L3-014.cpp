#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
array<int, N> d, hc;
array<bool, N> vis;
array<int, M> pth;
struct Node
{
    int d, u, id;
    bool operator<(const Node &a) const { return d > a.d; }
};
struct Edge
{
    int fr, to, di, id;
};
using G = vector<vector<int>>;
using E = vector<Edge>;

void dijk(G &gr, E &edg, int s)
{
    d.fill(INF);
    d[s] = 0;
    hc.fill(INF);
    vis.fill(0);
    hc[0] = 0;
    priority_queue<Node> pq;
    pq.push(Node{0, s, INF});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int u = x.u;
        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        if (d[u] < x.d)
            continue;
        for (auto i : gr[u])
        {
            auto &e = edg[i];
            int to = e.fr == u ? e.to : e.fr;
            int dif = x.id == e.id ? 0 : 1;
            if (d[to] == d[u] + e.di)
            {
                if (hc[to] > hc[u] + dif)
                {
                    pth[to] = i;
                    hc[to] = hc[u] + dif;
                }
            }
            else if (d[to] > d[u] + e.di)
            {
                d[to] = d[u] + e.di;
                pth[to] = i;
                hc[to] = hc[u] + dif;
                pq.push(Node{d[to], to, e.id});
            }
        }
    }
}

vector<Edge> troad;
void out(E &edg, int s, int t, int id)
{
    int i = pth[t];
    auto &e = edg[i];
    int j = e.fr == t ? e.to : e.fr;
    if (j != s)
        out(edg, s, j, e.id);
    troad.push_back(Edge{j, t, 0, e.id});
}
void merge(vector<Edge> &edg)
{
    int idx = 0;
    for (int i = 1; i < edg.size(); ++i)
    {
        if (edg[idx].id == edg[i].id)
        {
            edg[idx].to = edg[i].to;
            edg.erase(edg.begin() + i);
            i--;
        }
        else
            idx = i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sm = 0;
    cin >> n;
    G gr;
    E edg;
    edg.resize(M);
    gr.resize(N);
    for (int i = 0; i < n; ++i)
    {
        int m, c, ne;
        cin >> m >> c;
        for (int j = 1; j < m; ++j)
        {
            cin >> ne;
            edg[sm] = Edge{c, ne, 1, i + 1};
            gr[c].push_back(sm);
            gr[ne].push_back(sm);
            sm++;
            c = ne;
        }
    }
    int k, u, v;
    cin >> k;
    while (k--)
    {
        cin >> u >> v;
        dijk(gr, edg, u);
        if (d[v] == INF)
        {
            cout << "Sorry, no line is available." << endl;
            continue;
        }
        troad.clear();
        out(edg, u, v, INF);
        merge(troad);
        cout << d[v] << endl;
        for (auto i : troad)
        {
            cout << "Go by the line of company #" << i.id << " from " << setw(4) << setfill('0') << i.fr << " to " << setw(4) << setfill('0') << i.to << "." << endl;
        }
    }
    return 0;
}