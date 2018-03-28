#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 7;
const int M = 1e5 + 7;
const int INF = 0x3f3f3f3f;
using G = vector<vector<int>>;
array<int, N> d, t, non;
array<int, M> pth;
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
    int fr, to, di, ti;
};
using E = vector<Edge>;
void dijk(G &gr, E &edg, int s)
{
    d.fill(INF);
    non.fill(0);
    d[s] = 0;
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
            int to = u == e.fr ? e.to : e.fr;
            if (d[to] == d[u] + e.di)
            {
                cout << to <<" " << u << endl;
                if (non[to] < non[u] + 1)
                    pth[to] = i;
            }
            else if (d[to] > d[u] + e.di)
            {
                d[to] = d[u] + e.di;
                pth[to] = i;
                non[to] = non[u] + 1;
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
        cout << s;
    cout << " => " << t;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m;
    G gr;
    E edg;
    gr.resize(n + 1);
    edg.resize(m + 1);
    for (int i = 0; i < m; ++i)
    {
        int fr, to, di, ti;
        bool ow = 0;
        cin >> fr >> to >> ow >> di >> ti;
        edg[i] = Edge{fr, to, di, ti};
        gr[fr].push_back(i);
        if (!ow)
            gr[to].push_back(i);
    }
    cin >> s >> t;
    dijk(gr, edg, s);
    cout << "Distance = " << d[t] << ": ";
    out(edg, s, t);
    cout << endl;

    return 0;
}