#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
array<int, N> d, hc;
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
    hc[0] = 0;
    priority_queue<Node> pq;
    pq.push(Node{0, s, INF});
    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int u = x.u;
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
void out(E &edg, int s, int t, int id)
{
    int i = pth[s];
    auto &e = edg[i];
    int j = e.fr == s ? e.to : e.fr;
    if (id != e.id)
    {
        cout << setw(4) << setfill('0') << s << "." << endl;
        cout << "Go by the line of company #" << e.id << " from ";
        cout << setw(4) << setfill('0') << s << " to ";
    }
    if (j != t)
        out(edg, j, t, e.id);
    else
        cout << setw(4) << setfill('0') << t << "." << endl;
    // if (j != s)
    //     out(edg, s, j, e.id);
    // else
    //     cout << s;
    // cout << " " << t;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sm = 0;
    cin >> n;
    G gr;
    E edg;
    gr.resize(N);
    for (int i = 0; i < n; ++i)   
    {
        int m, c, ne;
        cin >> m;
        if (m)
            cin >> c;
        for (int j = 1; j < m; ++j)
        {
            cin >> ne;
            edg.push_back(Edge{c, ne, 1, i + 1});
            gr[c].push_back(sm);
            gr[ne].push_back(sm);
            sm++;
            c = ne;
        }
    }
    int k, u, v;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> u >> v;
        dijk(gr, edg, v);
        if (d[u] == INF)
            cout << "Sorry, no line is available." << endl;
        else
        {
            if (u != v)
            {
                cout << d[u] << endl;
                int i = pth[u];
                auto &e = edg[i];
                cout << "Go by the line of company #" << e.id << " from ";
                cout << setw(4) << setfill('0') << u << " to ";
                int j = e.fr == u ? e.to : e.fr;
                if (j != v)
                    out(edg, j, v, e.id);
                else
                    cout << setw(4) << setfill('0') << v << "." << endl;
            }
            else
            {
                cout << 0 << endl
                     << "Go by the line of company #" << 0 << " from " << setw(4) << setfill('0') << u << " to " << setw(4) << setfill('0') << v << "." << endl;
            }
        }
    }
    return 0;
}