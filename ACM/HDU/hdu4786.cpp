#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define MN 100010
using namespace std;
#define G vector<vector<Edge>>
int ct = 0;
struct Edge
{
    int v;
    bool c;
    Edge() = default;
    Edge(int v, bool c)
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
int mst(G &gr);
int nmst(G &gr);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int fib[27];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 27; i++)
        fib[i] = fib[i - 2] + fib[i - 1];
    int T, n, m;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> m;
        G gr;
        gr.resize(n);
        int u, v;
        bool c, fl = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr[u - 1].push_back(Edge(v - 1, c));
            gr[v - 1].push_back(Edge(u - 1, c));
        }
        ct = 1;
        int a1 = mst(gr);
        int a2 = nmst(gr);
        cout << "Case #" << t << ": ";
        for (int i = 1; i < 27; ++i)
            if (fib[i] <= a1 && fib[i] >= a2)
            {
                fl = 1;
                break;
            }
        if (fl && ct == n)
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
    mrk[0] = 1;
    for (auto e : gr[0])
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

int nmst(G &gr)
{
    int sum = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    array<bool, MN> mrk;
    mrk.fill(0);
    mrk[0] = 1;
    for (auto e : gr[0])
        pq.push(e);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        sum += e.c;
        mrk[v] = 1;
        for (auto e : gr[v])
            if (!mrk[e.v])
                pq.push(e);
    }
    return sum;
}