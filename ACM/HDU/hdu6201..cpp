#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 2e6 + 7;
const int M = 1e6 + 7;
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
    onq.fill(0);
    cnt.fill(0);
    d.fill(INF);
    d[s] = 0;
    onq[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        onq[u] = false;
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
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        G gr;
        E edg;
        gr.resize(N);
        edg.resize(N);
        for (int i = 1; i <= n; ++i)
        {
            int di;
            cin >> di;
            edg[n + i] = Edge(n+1, i, -di);
            gr[n+1].push_back(n + i);
            edg[2 * n + i] = Edge(i, n+2, di);
            gr[i].push_back(2 * n + i);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            int fr, to, di;
            cin >> fr >> to >> di;
            edg[i] = Edge(fr, to, di);
            gr[fr].push_back(i);
            gr[to].push_back(i); // if Two-Way
        }
        if (ford(gr, edg, n + 1, n + 2))
            cout << -d[n + 2] << endl;
        else
            cout << "No response." << endl;
    }
    return 0;
}