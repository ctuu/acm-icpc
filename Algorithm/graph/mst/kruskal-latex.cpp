#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5 + 7;
#define M 7
#define K 11
array<int, 10> mrk;
array<int, N> p;
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
struct Edge
{
    int u, v, c;
    Edge() = default;
    Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
using G = pair<vector<Edge>, int>;
vector<Edge> sele;
int cot = 0;
string pos[M] = {"(0,0)", "(0,2)", "(2,1)", "(3,0)", "(4,1)", "(4,-1)", "(2,-1)"};
void print()
{
    if (cot % 4 == 0)
        cout << "\\begin{figure}[H]\n\\centering\n\\begin{subfigure}{.25\\textwidth}\n\\centering\n\\begin{tikzpicture}[scale=0.6, auto]" << endl;
    else
        cout << "\\caption*{A subfigure}\n\\end{subfigure}%\n\\begin{subfigure}{.25\\textwidth}\n\\centering\n\\begin{tikzpicture}[scale=0.6, auto]" << endl;
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
    cout << "\\foreach \\source/ \\dest in {";
    count = 0;
    for (auto e : sele)
    {
        if (count)
            cout << ",";
        count++;
        cout << (char)(e.u + 'a') << "/" << (char)(e.v + 'a');
    }
    cout << "}\\path[selected edge] (\\source) -- (\\dest);" << endl;
    cout << "\\foreach \\source/ \\dest /\\weight in {a/b/7, a/c/15, a/d/5, a/g/9, b/c/8, c/d/9, c/e/5, d/e/7, d/f/6,e/f/8, f/g/11}\\path[edge] (\\source) -- node[weight] {$\\weight$} (\\dest);" << endl;
    cout << "\\end{tikzpicture}" << endl;
    if ((cot % 4 == 0 && cot != 0) || cot == 6)
        cout << "\\caption*{A subfigure}\n\\end{subfigure}\n\\end{figure}" << endl;
    cot++;
}
int mst(G &gr)
{
    for (int i = 0; i < N; ++i)
        p[i] = i;
    int sum = 0, ct = 0;
    mrk.fill(0);
    vector<Edge> pa = gr.first;
    sort(pa.begin(), pa.end(), [](Edge &a, Edge &b) { return a.c < b.c; });
    for (auto e : pa)
    {
        int u = find(e.u), v = find(e.v);
        if (u == v)
            continue;
        mrk[u] = mrk[v] = 1;
        sele.push_back(e);
        print();
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
    int n, m, c;
    char u, v;
    cin >> n >> m;
    G gr;
    gr.second = n;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        gr.first.push_back(Edge(u - 'a', v - 'a', c));
    }
    int ans = mst(gr);
    cout << ans << endl;
    return 0;
}
// 7 11
// a b 7
// a c 15
// a d 5
// a g 9
// b c 8
// c d 9
// c e 5
// d e 7
// d f 6
// e f 8
// f g 11