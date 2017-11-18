#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using LL = long long;
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LL n, x, y, tmp;
    cin >> n >> x >> y;
    vector<LL> a, b;
    for (LL i = 0; i < n; ++i)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (LL i = 0; i < n; ++i)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (LL i = 0; i < n && x; ++i)
    {
        --x;
        if (a[i] >= y)
            break;
        a[i] = y;
    }
    LL ans = 0;
    sort(a.begin(), a.end());
    for (LL i = 0; i < n; ++i)
        if (a[i] <= b[i])
            ans = max(ans, b[i] - a[i]);
    cout << ans << endl;
    return 0;
}