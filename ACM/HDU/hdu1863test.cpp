#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define MV 5000
using namespace std;
int ct = 0;
class Edge
{
  private:
    int v, w;
    int wei;

  public:
    Edge(int v, int w, int wei)
    {
        this->v = v;
        this->w = w;
        this->wei = wei;
    }
    int either()
    {
        return v;
    }
    int other(int v)
    {
        if (v == this->v)
            return w;
        else
            return v;
    }
    int weight()
    {
        return wei;
    }
    friend bool operator>(const Edge &a, const Edge &b)
    {
        return a.wei > b.wei;
    }
    friend bool operator<(const Edge &a, const Edge &b)
    {
        return a.wei < b.wei;
    }
};
class Wgraph
{
  private:
    int V, E;
    vector<vector<Edge>> gr;

  public:
    Wgraph(int V)
    {
        gr.resize(V);
    }
    void adde(int v, int w, int wei)
    {
        gr[v].push_back(Edge(v, w, wei));
    }
    vector<Edge> adj(int v)
    {
        return gr[v];
    }
};
class Prim
{
  private:
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    array<bool, MV> mrk;
    queue<Edge> mst;
    void visit(Wgraph gr, int v)
    {
        ++ct;
        mrk[v] = 1;
        for (auto e : gr.adj(v))
        {
            if (!mrk[e.other(v)])
                pq.push(e);
        }
    }

  public:
    long long calc(Wgraph gr)
    {
        int sum = 0;
        mrk.fill(0);
        visit(gr, 0);
        while (!pq.empty())
        {
            Edge e = pq.top();
            pq.pop();
            int v = e.either(), w = e.other(v);
            if (mrk[v] && mrk[w])
                continue;
            mst.push(e);
            sum += e.weight();
            if (!mrk[v])
                visit(gr, v);
            if (!mrk[w])
                visit(gr, w);
        }
        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while (cin >> m >> n && m)
    {
        Wgraph gr = Wgraph(n);
        int u, v, c;
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> c;
            gr.adde(u - 1, v - 1, c);
        }
        ct = 0;
        Prim prim;
        int ans = prim.calc(gr);
        if (ct == n)
            cout << ans << endl;
        else
            cout << "?" << endl;
    }
    return 0;
}
