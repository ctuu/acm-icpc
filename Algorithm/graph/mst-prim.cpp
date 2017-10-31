#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
#define MV 50000
using namespace std;
class Edge
{
  private:
    int v, w;
    double wei;

  public:
    Edge(int v, int w, double wei)
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
    double weight()
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
    void adde(int v, int w, double wei)
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
        double sum = 0;
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
    cin >> n >> m;
    Wgraph gr = Wgraph(n);
    int v, w;
    double wei;
    for (int i = 0; i < m; ++i)
    {
        cin >> v >> w >> wei;
        gr.adde(v-1, w-1, wei);
    }
    Prim prim;
    cout << prim.calc(gr) << endl;
    return 0;
}
