#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> t, b, bb;
    t.resize(n);
    b.resize(m);
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        long long tmp = -INF;
        for (int j = 0; j < m; ++j)
            tmp = max(tmp, t[i] * b[j]);
        bb.push_back(tmp);
    }
    sort(bb.begin(), bb.end());
    cout << *(++bb.rbegin());
    return 0;
}