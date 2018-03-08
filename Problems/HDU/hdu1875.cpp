#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const int N = 300;
array<int, N> p;
int V;
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
struct Edge
{
    int u, v;
    double c;
    Edge() = default;
    Edge(int u, int v, double c) : u(u), v(v), c(c) {}
};
using G = vector<Edge>;
double mst(G &gr)
{
    for (int i = 0; i < N; ++i)
        p[i] = i;
    double sum = 0;
    int ct = 0;
    sort(gr.begin(), gr.end(), [](Edge a, Edge b) { return a.c < b.c; });
    for (auto e : gr)
    {
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        p[u] = v;
        ++ct;
        sum += e.c;
    }
    if (ct == V - 1)
        return sum;
    else
        return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, x, y;
        vector<pair<int, int>> pos;
        cin >> n;
        G gr;
        V = n;
        pos.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            pos[i] = make_pair(x, y);
        }
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                double res = sqrt((double)(pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (double)(pos[i].second - pos[j].second) * (pos[i].second - pos[j].second));
                if (res < 10 || res > 1000)
                    continue;
                gr.push_back(Edge(i, j, res));
                // cout << i << " " << j << " " << res << endl;
            }
        double ans = mst(gr);
        if (ans > 0)
            cout << fixed << setprecision(1) << ans * 100 << endl;
        else
            cout << "oh!" << endl;
    }

    return 0;
}