#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
const int N = 3000;
array<int, N> p;
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
struct Edge
{
    int u, v, c;
    Edge() = default;
    Edge(int u, int v, int c): u(u), v(v), c(c) {}
};
using G  = vector<Edge>;
int mst(G &gr)
{
    for(int i = 0; i < N; ++i)
        p[i] = i;
    int sum = 0, ct = 0;
    vector<Edge> pa = gr;
    sort(pa.begin(), pa.end(), [](Edge a, Edge b) { return a.c < b.c; });
    for(auto e : pa)
    {
        int u = find(e.u), v = find(e.v);
        if(u == v)
            continue;
        p[u] = v;
        ++ct; 
        sum += e.c;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, u, v, c;
    while(cin >> n)
    {
        G gr;
        if(n == 0)
            return 0; 
        for(int i = 0; i < n*(n-1)/2; ++i)
        {
            cin >> u >> v >> c;
            gr.push_back(Edge(u, v, c));
        }
        int ans  = mst(gr);
        cout << ans << endl;
    }
    return 0;
}