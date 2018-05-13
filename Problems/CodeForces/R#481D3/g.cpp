#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 107;
array<vector<int>, N> tb;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    array<int, N> s, d, c, t, ta;
    ta.fill(0);
    c.fill(0);
    t.fill(0);
    for (int i = 1; i <= m; ++i)
    {
        cin >> s[i] >> d[i] >> c[i];
        for (int j = s[i]; j < d[i]; ++j)
            tb[j].push_back(i);
        t[d[i]] = m + 1;
        ta[d[i]] = i;
        if (d[i] - s[i] < c[i])
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    for (auto &cr : tb)
    {
        sort(cr.begin(), cr.end(), [d](int a, int b) {
            return d[a] < d[b];
        });
    }
    for (int i = 1; i <= n; ++i)
    {
        if (t[i] == m + 1)
        {
            if (c[ta[i]] > 0)
            {
                cout << "-1" << endl;
                return 0;
            }
            continue;
        }
        for (auto cr : tb[i])
            if (c[cr] > 0)
            {
                c[cr]--;
                t[i] = cr;
                break;
            }
    }
    for (int i = 1; i <= n; ++i)
        cout << t[i] << " ";
    return 0;
}