#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define G array<vector<Edge>, MN>
const int MN = 1e5 + 7;
int ct = 0;
struct Edge
{
    int v;
    int c;
    Edge() = default;
    Edge(int v, int c)
    {
        this->v = v;
        this->c = c;
    }
    friend bool operator>(const Edge &a, const Edge &b)
    {
        return a.c > b.c;
    }
    friend bool operator<(const Edge &a, const Edge &b)
    {
        return a.c < b.c;
    }
};
G gr;
int mst(G &gr);
int mst2(G &gr);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int fib[35];
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 31; i++)
        fib[i] = fib[i - 2] + fib[i - 1];
    int T, n, m;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
            gr[i].clear();
        // gr.resize(n);
        int u, v;
        bool c, fl = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr[u].push_back(Edge(v, c));
            gr[v].push_back(Edge(u, c));
        }
        ct = 1;
        cout << "Case #" << t << ": ";
        int a1 = mst(gr);
        if (ct != n)
        {
            cout << "No" << endl;
            continue;
        }
        int a2 = mst2(gr);
        // cout <<a1 << " " << a2<<endl;
        for (int i = 1; i <= 33; ++i)
            if (fib[i] <= a1 && fib[i] >= a2)
            {
                fl = 1;
                break;
            }
        if (fl)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

int mst(G &gr)
{
    int sum = 0;
    priority_queue<Edge> pq;
    array<bool, MN> mrk;
    mrk.fill(0);
    mrk[1] = 1;
    for (auto e : gr[1])
        pq.push(e);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        sum += e.c;
        ++ct;
        mrk[v] = 1;
        for (auto e : gr[v])
            if (!mrk[e.v])
                pq.push(e);
    }
    return sum;
}

int mst2(G &gr)
{
    int sum = 0;
    priority_queue<Edge> pq;
    array<bool, MN> mrk;
    mrk.fill(0);
    mrk[1] = 1;
    for (auto e : gr[1])
        pq.push(Edge(e.v, -e.c));
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        sum -= e.c;
        mrk[v] = 1;
        for (auto e : gr[v])
            if (!mrk[e.v])
                pq.push(Edge(e.v, -e.c));
    }
    return sum;
}