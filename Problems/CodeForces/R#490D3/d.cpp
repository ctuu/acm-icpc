#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 7;
using LL = long long;
array<LL, N> a;
vector<pair<LL, LL>> e;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    LL tr = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        e.push_back({a[i] % m, i});
    }
    LL to = n / m;
    sort(e.begin(), e.end());
    LL en = n;
    for (LL i = 0; i < en; ++i)
    {
        LL si = (i + n - en) / to;
        if (e[i].first > si)
        {
            auto c = e.back();
            e.pop_back();
            LL k = m + si - c.first;
            tr += k;
            a[c.second] += k;
            --i;
            --en;
        }
        else
        {
            LL k = si - e[i].first;
            tr += k;
            a[e[i].second] += k;
        }
    }
    cout << tr << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    return 0;
}