#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
#define N 100007
#define G vector<vector<Edge>>
int ct = 0;
char ty[2003][8];
bool mrk[N];
int dist[N];
struct Edge
{
    int v, c;
    Edge(){};
    Edge(int v, int c) : v(v), c(c) {}
    bool operator<(const Edge &a) const { return c > a.c; }
};
int mst(G &gr, int size)
{
    int sum = 0;
    map<int, int> idx;
    for (int i = 0; i < N; ++i)
    {
        dist[i] = INF;
        mrk[i] = 0;
    }
    idx[0] = 0;
    dist[0] = 0;
    while (!idx.empty())
    {
        map<int, int>::iterator iter = idx.begin();
        int u = iter->second;
        idx.erase(iter);
        mrk[u] = 1;
        int tmp = gr[u].size();
        for (int i = 0; i < tmp; ++i)
        {
            Edge e = gr[u][i];
            int v = e.v;
            if (mrk[v])
                continue;
            if (e.c < dist[v])
            {
                dist[v] = e.c;
                idx[dist[v]] = v;
            }
        }
    }
    for (int i = 0; i < size; ++i)
        sum += dist[i];
    return sum;
}
int dis(int a, int b)
{
    int sum = 0;
    for (int i = 0; i < 7; ++i)
        sum += (ty[a][i] != ty[b][i]);
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n)
    {
        G gr;
        gr.resize(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> ty[i];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                gr[i].push_back(Edge(j, dis(i, j)));
                gr[j].push_back(Edge(i, dis(i, j)));
            }
        int ans = mst(gr, n);
        cout << "The highest possible quality is 1/" << ans << "." << endl;
    }
    return 0;
}