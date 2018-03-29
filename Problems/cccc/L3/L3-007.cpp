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
array<int, M> pth, pth2;
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
    non.fill(INF);
    non[s] = 0;
    t[s] = 0;
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
                if (non[to] > non[u] + 1)
                {
                    pth[to] = i;
                    non[to] = non[u] + 1;
                }
            }
            else if (d[to] > d[u] + e.di)
            {
                pth[to] = i;
                non[to] = non[u] + 1;
                d[to] = d[u] + e.di;
                pq.push(Node{d[to], to});
            }
        }
    }
}

void dijt(G &gr, E &edg, int s)
{
    t.fill(INF);
    d.fill(INF);
    t[s] = 0;
    d[s] = 0;
    priority_queue<Node> pq;
    pq.push(Node{0, s});
    while (!pq.empty())
    {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        if (t[u] < x.d)
            continue;
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = u == e.fr ? e.to : e.fr;
            if (t[to] == t[u] + e.ti)
            {
                if (d[to] > d[u] + e.di)
                {
                    pth2[to] = i;
                }
            }
            else if (t[to] > t[u] + e.ti)
            {
                pth2[to] = i;
                d[to] = d[u] + e.di;
                t[to] = t[u] + e.ti;
                pq.push(Node{t[to], to});
            }
        }
    }
}





void out(E &edg, int s, int t, array<int, M> &pth)
{
    int i = pth[t];
    auto &e = edg[i];
    int j = e.fr == t ? e.to : e.fr;
    if (j != s)
        out(edg, s, j, pth);
    else
        cout << s;
    cout << " => " << t;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, tt;
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
    cin >> s >> tt;
    dijt(gr, edg, s);
    int ife = d[tt];
    dijk(gr, edg, s);
    cout << "Time = " << t[tt];
    if(d[tt] != ife)
    {
        cout  << ": ";
        out(edg, s, tt, pth2);
        cout << endl;
    }
    else
    cout << "; ";
    cout << "Distance = " << d[tt] << ": ";
    out(edg, s, tt, pth);
    cout << endl;

    return 0;
}