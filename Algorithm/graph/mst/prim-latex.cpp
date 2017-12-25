#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
#define M 7
#define K 11
int ct = 0;
struct Edge
{
    int v, c;
    Edge() = default;
    Edge(int v, int c) : v(v), c(c) {}
    bool operator<(const Edge &a) const { return c > a.c; }
};
string pos[M] = {"(0,0)", "(0,2)", "(2,1)", "(3,0)", "(4,1)", "(4,-1)", "(2,-1)"};
using G = vector<vector<Edge>>;
array<bool, N> mrk;
vector<Edge> sele;
void print()
{
    cout << "\\begin{tikzpicture}[scale=1.2, auto]" << endl;
    cout << "\\foreach \\pos/\\name in {";
    int count = 0;
    for (int i = 0; i < M; ++i)
    {
        if (!mrk[i])
        {
            if (count)
                cout << ",";
            count++;
            cout << "{" << pos[i] << "/" << (char)('a' + i) << "}";
        }
    }
    cout << "}\\node[vertex] (\\name) at \\pos {$\\name$};" << endl;
    cout << "\\foreach \\pos/\\name in {";
    count = 0;
    for (int i = 0; i < M; ++i)
    {
        if (mrk[i])
        {
            if (count)
                cout << ",";
            count++;
            cout << "{" << pos[i] << "/" << (char)('a' + i) << "}";
        }
    }
    cout << "}\\node[selected vertex] (\\name) at \\pos {$\\name$};" << endl;
    cout <<"\\foreach \\source/ \\dest /\\weight in {a/b/7, a/c/15, a/d/5, a/g/9, b/c/8, c/d/9, c/e/5, d/e/7, d/f/6,e/f/8, f/g/11}\\path[edge] (\\source) -- node[weight] {$\\weight$} (\\dest);"<<endl;
    cout << "\\end{tikzpicture}" << endl;
    cout << endl;
}
int mst(G &gr)
{
    int sum = 0;
    priority_queue<Edge> pq;
    mrk.fill(0);
    mrk[0] = 1;
    print();
    for (auto e : gr[0])
        pq.push(e);
    while (!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int v = e.v;
        if (mrk[v])
            continue;
        mrk[v] = 1;
        sum += e.c;
        sele.push_back(e);
        print();
        for (auto e : gr[v])
            if (!mrk[e.v])
                pq.push(e);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    char u, v;
    cin >> n >> m;
    G gr;
    gr.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        gr[u - 'a'].push_back(Edge(v - 'a', c));
        gr[v - 'a'].push_back(Edge(u - 'a', c));
    }
    int ans = mst(gr);
    cout << ans << endl;
    return 0;
}