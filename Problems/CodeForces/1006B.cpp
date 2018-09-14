#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using PII = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, t;
    cin >> n >> k;
    vector<PII> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        v.push_back({t, i + 1});
    }
    sort(v.begin(), v.end(), greater<PII>());
    vector<int> res;
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ans += v[i].first;
        res.push_back(v[i].second);
    }
    cout << ans << endl;
    sort(res.begin(), res.end());
    if (k > 1)
    {
        cout << res[0] << " ";
        for (int i = 1; i < k - 1; ++i)
        {
            cout << res[i] - res[i - 1] << " ";
        }
        cout << n - res[k - 2];
    }
    else
        cout << n << endl;
    return 0;
}
