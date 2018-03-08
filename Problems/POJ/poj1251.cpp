#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 100007
#define G vector<vector<Edge> >
int ct = 0;
struct Edge
{
    int v, c;
    Edge(){};
    Edge(int v, int c) : v(v), c(c) {}
    bool operator<(const Edge &a) const { return c > a.c; }
};
bool mrk[N];

int mst(G &gr)
{
    int sum = 0;
    priority_queue<Edge> pq;
    for (int i = 0; i < N; ++i)
        mrk[i] = 0;
    mrk[0] = 1;
    int tmp = gr[0].size();
    for (int i = 0; i < tmp; ++i)
        pq.push(gr[0][i]);
    // for (auto e : gr[0])
    //     pq.push(e);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        mrk[v] = 1;
        sum += e.c;
        tmp = gr[v].size();
        for(int i = 0; i < tmp; ++i)
            if(!mrk[gr[v][i].v])
                pq.push(gr[v][i]);
        // for (auto e : gr[v])
        //     if (!mrk[e.v])
        //         pq.push(e);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    while (cin >> n && n)
    {
        G gr;
        gr.resize(n + 1);
        for (int i = 0; i < n - 1; ++i)
        {
            char u ,v;
            cin >> u >> m;
            for (int j = 0; j < m; ++j)
            {
                cin >> v >> c;
                gr[u - 'A'].push_back(Edge(v - 'A', c));
                gr[v - 'A'].push_back(Edge(u - 'A', c));
            }
        }
        int ans = mst(gr);
        cout << ans << endl;
    }
    return 0;
}