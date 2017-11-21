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
array<int, N> onq, d, cnt;
array<int, M> pth;
struct Edge
{
    int fr, to, di;
    Edge() = default;
    Edge(int u, int v, int w) : fr(u), to(v), di(w) {}
};
using E = vector<Edge>;
bool ford(G &gr, E &edg, int s, int n)
{
    queue<int> q;
    cnt.fill(0); //访问某点次数
    d.fill(INF);
    d[s] = 0;
    onq[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : gr[u])
        {
            Edge &e = edg[i];
            int to = (e.fr == u) ? e.to : e.fr;
            if (d[u] < INF && d[to] > d[u] + e.di)
            {
                d[to] = d[u] + e.di;
                pth[to] = i;
                if (!onq[to])
                {
                    q.push(to);
                    onq[to] = 1;
                    if (++cnt[to] > n)
                        return false;
                }
            }
        }
        onq[u] = false;
    }
    return true;
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
        int fr, to, di;
        cin >> fr >> to >> di;
        edg[i] = Edge(fr, to, di);
        gr[fr].push_back(i);
        gr[to].push_back(i); // if Two-Way
    }
    cin >> s >> t;
    if (ford(gr, edg, s, n))
        cout << d[t] << endl;
    else
        cout << "false" << endl;
    return 0;
}