#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int N = 1003;
array<bool, N> vid, vih;
array<int, N> ar;
array<vector<int>, N> ids;
map<int, vector<int>> hs;
int cnt;
void cal(int cu)
{
    if (vid[cu])
        return;
    ++ar[cnt];
    vid[cu] = 1;
    for (auto i : ids[cu])
    {
        if (vih[i])
            continue;
        vih[i] = 1;
        for (auto j : hs[i])
            cal(j);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vid.fill(0);
    vih.fill(0);
    ar.fill(0);
    int n, m, t;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char ch;
        cin >> m >> ch;
        for (int j = 0; j < m; ++j)
        {
            cin >> t;
            ids[i].push_back(t);
            hs[t].push_back(i);
        }
    }
    cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (vid[i])
            continue;
        cal(i);
        cnt++;
    }
    cout << cnt << endl;
    sort(ar.begin(), ar.begin() + cnt, greater<int>());
    for (int i = 0; i < cnt; ++i)
    {
        if (i)
            cout << " ";
        cout << ar[i];
    }
    return 0;
}