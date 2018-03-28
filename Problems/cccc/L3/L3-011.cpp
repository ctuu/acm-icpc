#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
using G = vector<vector<int>>;
array<int, N> d, dn;
array<int, N> ptc, kiln, towns;
array<int, M> pth;
map<string, int> nti;
map<int, string> itn;
int idx = 0;
struct Node
{
    int d, u;
    bool operator<(const Node &a) const
    {
        return d > a.d;
    }
};
struct Edge
{
    int fr, to, di;
};
using E = vector<Edge>;

void dijk(G &gr, E &edg, int s)
{
    d.fill(INF);
    d[s] = 0;
    ptc[s] = 1;
    priority_queue<Node> pq;
    pq.push(Node{0, s});
    while (!pq.empty())
    {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (d[u] < x.d)
            continue;
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = (e.fr == u) ? e.to : e.fr;
            if (d[to] == d[u] + e.di)
            {
                if (towns[to] == towns[u] + 1)
                {
                    if (kiln[to] < kiln[u] + dn[to])
                    {
                        kiln[to] = kiln[u] + dn[to];
                        pth[to] = i;
                    }
                }
                else if (towns[to] < towns[u] + 1)
                {
                    kiln[to] = kiln[u] + dn[to];
                    towns[to] = towns[u] + 1;
                    pth[to] = i;
                }
                ptc[to] += ptc[u];
            }
            if (d[to] > d[u] + e.di)
            {
                towns[to] = towns[u] + 1;
                kiln[to] = kiln[u] + dn[to];
                ptc[to] = ptc[u];
                pth[to] = i;
                d[to] = d[u] + e.di;
                pq.push(Node{d[to], to});
            }
        }
    }
}

void out(E &edg, int s, int t)
{
    int i = pth[t];
    auto &e = edg[i];
    int j = e.fr == t ? e.to : e.fr;
    if (j != s)
        out(edg, s, j);
    else
        cout << itn[s];
    cout << "->" << itn[t];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string sn, en, ts;
    cin >> sn >> en;
    itn[idx] = sn;
    nti[sn] = idx++;
    G gr;
    E edg;
    kiln.fill(0);
    towns.fill(0);
    dn.fill(0);
    ptc.fill(0);
    gr.resize(n + 1);
    edg.resize(m + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> ts >> dn[idx];
        itn[idx] = ts;
        nti[ts] = idx++;
    }
    for (int i = 0; i < m; ++i)
    {
        string a, b;
        int di;
        cin >> a >> b >> di;
        edg[i] = Edge{nti[a], nti[b], di};
        gr[nti[a]].push_back(i);
        gr[nti[b]].push_back(i);
    }
    dijk(gr, edg, 0);
    out(edg, nti[sn], nti[en]);
    cout << endl;
    cout << ptc[nti[en]] << " " << d[nti[en]] << " " << kiln[nti[en]] << endl;
    return 0;
}
