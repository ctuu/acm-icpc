#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define MN 100005
using namespace std;
#define G vector<vector<Edge>>
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
int mst2(G &gr);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<bool, MN> ar;
    ar.fill(0);
    for (int a = 1, b = 1; a < MN && b < MN; swap(a, b))
    {
        ar[a] = 1;
        a += b;
    }
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
        }
        int a1 = mst(gr);
        int a2 = mst2(gr);
        cout << "Case #" << t << ": ";
        for (int i = a2; i <= a1; ++i)
            if (ar[i])
            {
                fl = 1;
                continue;
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
    for (auto i : gr[0])
        pq.push(i);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        sum += e.c;
        if (!mrk[v])
        {
            mrk[v] = 1;
            for (auto i : gr[v])
                pq.push(i);
        }
    }
    return sum;
}

int mst2(G &gr)
{
    int sum = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    array<bool, MN> mrk;
    mrk.fill(0);
    for (auto i : gr[0])
        pq.push(i);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        sum += e.c;
        if (!mrk[v])
        {
            mrk[v] = 1;
            for (auto i : gr[v])
                pq.push(i);
        }
    }
    return sum;
}