#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 100007
#define G vector<vector<Edge> >
int ct = 0;
struct Sphere
{
    double x, y, z, r;
    Sphere() {}
    Sphere(double x, double y, double z, double r) : x(x), y(y), z(z), r(r) {}
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

double mst(G &gr)
{
    double sum = 0;
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
        sum += e.c;
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
    int n;
    double x, y, z, r;
    Sphere itm[103];
    while (cin >> n && n)
    {
        G gr;
        gr.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y >> z >> r;
            itm[i] = Sphere(x, y, z, r);
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                double c = sqrt((itm[i].x - itm[j].x) * (itm[i].x - itm[j].x) + (itm[i].y - itm[j].y) * (itm[i].y - itm[j].y) + (itm[i].z - itm[j].z) * (itm[i].z - itm[j].z));
                c -= (itm[i].r + itm[j].r);
                if (c <= 0)
                {
                    gr[i].push_back(Edge(j, 0));
                    gr[j].push_back(Edge(i, 0));
                }
                else
                {
                    gr[i].push_back(Edge(j, c));
                    gr[j].push_back(Edge(i, c));
                }
            }
        double ans = mst(gr);
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}