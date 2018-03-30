#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e3 + 13;
const int M = 1e6 + 7;
const int INF = 0x3f3f3f3f;
array<int, N> d;
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
    int fr, to, di;
};
struct Tra
{
    int id, ms, avg;
};
using G = vector<vector<int>>;
using E = vector<Edge>;
void dijk(G &gr, E &edg, int s)
{
    d.fill(INF);
    d[s] = 0;
    priority_queue<Node> qu;
    qu.push(Node{0, s});
    while (!qu.empty())
    {
        auto x = qu.top();
        qu.pop();
        int u = x.u;
        if (d[u] < x.d)
            continue;
        for (auto i : gr[u])
        {
            auto &e = edg[i];
            int to = u == e.fr ? e.to : e.fr;
            if (d[to] > d[u] + e.di)
            {
                d[to] = d[u] + e.di;
                pth[to] = i;
                qu.push(Node{d[to], to});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G gr;
    E edg;
    int n, m, k, ds;
    cin >> n >> m >> k >> ds;
    gr.resize(n + m + 3);
    edg.resize(k + 3);
    for (int i = 0; i < k; ++i)
    {
        string a, b;
        int di, u, v;
        cin >> a >> b >> di;
        u = a[0] == 'G' ? n + stoi(a.substr(1)) : stoi(a);
        v = b[0] == 'G' ? n + stoi(b.substr(1)) : stoi(b);
        edg[i] = Edge{u, v, di};
        gr[u].push_back(i);
        gr[v].push_back(i);
    }
    vector<Tra> trs;
    for (int i = 1; i <= m; ++i)
    {
        dijk(gr, edg, n + i);
        int ms = INF;
        int avgs = 0;
        for (int j = 1; j <= n; ++j)
        {
            ms = min(d[j], ms);
            if (d[j] > ds)
            {
                ms = INF;
                break;
            }
            avgs = avgs + d[j];
        }
        if (ms != INF)
            trs.push_back(Tra{i, ms, avgs});
    }
    sort(trs.begin(), trs.end(), [](Tra a, Tra b) {
        if (a.ms == b.ms)
        {
            if (a.avg == b.avg)
                return a.id < b.id;
            return a.avg < b.avg;
        }
        return a.ms > b.ms;
    });
    if (trs.empty())
        cout << "No Solution" << endl;
    else
    {
        cout << "G" << trs[0].id << endl;
        cout << fixed << setprecision(1) << 1.0 * trs[0].ms << " " << 1.0 * trs[0].avg / n  ;
    }
    return 0;
}