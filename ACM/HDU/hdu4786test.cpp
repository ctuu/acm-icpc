#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MN 100010
#define G vector<vector<Edge>>
int ct = 0;
int ct2 = 0;
struct Edge
{
    int u, v, c;
    Edge() = default;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
    int eir()
    {
        return u;
    }
    int oth(int x)
    {
        if (x == this->u)
            return v;
        else
            return u;
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
    int fib[35];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 31; i++)
        fib[i] = fib[i - 2] + fib[i - 1];
    int T, n, m;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> m;
        G gr;
        gr.resize(n);
        int u, v, c;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr[u - 1].push_back(Edge(u - 1, v - 1, c));
        }
        ct = 1;
        ct2 = 1;
        int a1 = mst(gr);
        int a2 = mst2(gr);
        bool fl = 0;
        cout << "Case #" << t << ": ";
        for (int i = 1; i <= 33; ++i)
            if (fib[i] <= a1 && fib[i] >= a2)
            {
                fl = 1;
                break;
            }
        if (fl && ct == n && ct2 == n)
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
        int v = e.eir();
        int w = e.oth(v);
        if (mrk[v] && mrk[w])
            continue;
        sum += e.c;
        if (!mrk[v])
        {
            ++ct;
            mrk[v] = 1;
            for (auto e : gr[v])
                if (!mrk[e.oth(v)])
                    pq.push(e);
        }
        if (!mrk[w])
        {
            ++ct;
            mrk[w] = 1;
            for (auto e : gr[w])
                if (!mrk[e.oth(w)])
                    pq.push(e);
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
    mrk[0] = 1;
    for (auto e : gr[0])
        pq.push(e);
    while (!pq.empty())
    {

        Edge e = pq.top();
        pq.pop();
        int v = e.eir();
        int w = e.oth(v);
        if (mrk[v] && mrk[w])
            continue;
        sum += e.c;
        if (!mrk[v])
        {
            ++ct2;
            mrk[v] = 1;
            for (auto e : gr[v])
                if (!mrk[e.oth(v)])
                    pq.push(e);
        }
        if (!mrk[w])
        {
            ++ct2;
            mrk[w] = 1;
            for (auto e : gr[w])
                if (!mrk[e.oth(w)])
                    pq.push(e);
        }
    }
    return sum;
}