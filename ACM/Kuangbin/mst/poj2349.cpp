#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 507
#define G vector<vector<Edge>>
int ct = 0;
vector<double> d;
struct coor
{
    double x, y;
    coor(){};
    coor(double x, double y) : x(x), y(y) {}
};
struct Edge
{
    int v;
    double c;
    Edge(){};
    Edge(int v, double c) : v(v), c(c) {}
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
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        mrk[v] = 1;
        d.push_back(e.c);
        // sum += e.c;
        tmp = gr[v].size();
        for (int i = 0; i < tmp; ++i)
            if (!mrk[gr[v][i].v])
                pq.push(gr[v][i]);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    coor itm[503];
    while (t--)
    {
        d.clear();
        int n, m, c;
        cin >> m >> n;
        G gr;
        gr.resize(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> itm[i].x >> itm[i].y;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                gr[i].push_back(Edge(j, sqrt((itm[i].x - itm[j].x) * (itm[i].x - itm[j].x) + (itm[i].y - itm[j].y) * (itm[i].y - itm[j].y))));
                gr[j].push_back(Edge(i, sqrt((itm[i].x - itm[j].x) * (itm[i].x - itm[j].x) + (itm[i].y - itm[j].y) * (itm[i].y - itm[j].y))));
            }
        mst(gr);
        sort(d.begin(), d.end());
        cout << fixed << setprecision(2) << d[n - m - 1] << endl;
    }
    return 0;
}