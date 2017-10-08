#include <iostream>
#include <algorithm>
#include <array>
#include <set>
#include <vector>
using namespace std;
array<vector<int>, 200005> gr;
array<long long, 200005> ar;
set<int> u, v;
void dfs(int be, int l, int a);
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ar.fill(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    u.insert(1);
    for (int i = 1; i <= n; ++i)
        for (auto j : gr[i])
            dfs(i, i, j);
    long long si = v.size();
    long long ans = 0;
    for (auto i : u)
        ans += si - gr[i].size();
    cout << ans;
    return 0;
}

void dfs(int be, int l, int a)
{
    if (be == a)
        return;
    if (u.count(a))
        v.insert(l);
    else if (v.count(a))
        u.insert(l);
    else if (u.count(l))
    {
        v.insert(a);
        for (auto j : gr[a])
            dfs(be, a, j);
    }
    else if (v.count(l))
    {
        u.insert(a);
        for (auto j : gr[a])
            dfs(be, a, j);
    }
}
