// 13 15
// 0 1
// 0 5
// 0 6
// 2 0
// 2 3
// 3 5
// 5 4
// 6 4
// 7 6
// 8 7
// 6 9
// 9 10
// 9 11
// 9 12
// 11 12
// 13 15
// 0 1
// 0 5
// 0 6
// 2 0
// 2 3
// 3 5
// 5 4
// 6 4
// 7 6
// 8 7
// 6 9
// 9 10
// 9 11
// 9 12
// 11 12

#include <algorithm>
#include <array>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define N 1000
array<bool, N> mrk;
array<bool, N> ons;
bool cycle = 0;
stack<int> po;
void dfs(vector<vector<int>> gr, int v);
void dag(vector<vector<int>> gr, int v);
void topo(vector<vector<int>> gr, int n);
void isDAG(vector<vector<int>> gr, int n);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mrk.fill(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> gr;
    gr.resize(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        gr[a].push_back(b);
    }
    isDAG(gr, n);
    if (!cycle)
    {
        topo(gr, n);
        while (!po.empty())
        {
            cout << po.top() << " ";
            po.pop();
        }
    }
    else
        cout << "hasCycle";
    return 0;
}

void isDAG(vector<vector<int>> gr, int n)
{
    for (int i = 0; i < n; ++i)
        if (!mrk[i] && !cycle)
            dag(gr, i);
    mrk.fill(0);
    ons.fill(0);
}
void dag(vector<vector<int>> gr, int v)
{
    ons[v] = 1;
    mrk[v] = 1;
    for (auto i : gr[v])
        if (cycle)
            return;
        else if (!mrk[i])
            dag(gr, i);
        else if (ons[i])
            cycle = 1;
    ons[v] = 0;
}

void topo(vector<vector<int>> gr, int n)
{
    for (int i = 0; i < n; ++i)
        if (!mrk[i])
            dfs(gr, i);
    mrk.fill(0);
}
void dfs(vector<vector<int>> gr, int v)
{
    mrk[v] = 1;
    for (auto i : gr[v])
        if (!mrk[i])
            dfs(gr, i);
    po.push(v);
}