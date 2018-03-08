#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 100007
#define G vector<vector<Edge>>
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
    int t, n, c;
    cin >> t;
    int adtr[1003];
    while (t--)
    {
        cin >> n;
        G gr;
        gr.resize(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> adtr[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                cin >> c;
                gr[i].push_back(Edge(j, c + adtr[i] + adtr[j]));
            }
        int ans = mst(gr);
        cout << ans << endl;
    }
    return 0;
}