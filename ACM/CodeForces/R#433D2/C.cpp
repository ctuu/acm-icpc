#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<PII> ar;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        ar.push_back(PII(i + 1, t));
    }
    sort(ar.begin(), ar.end(), [](PII a, PII b) {
            return a.second > b.second;
    });
    long long ans = 0;
    int li[300000];
    for (int i = 0; i < n; ++i)
    {
        ++k;
        auto it = upper_bound(ar.begin(), ar.end(), PII(k, 0), [](PII a, PII b) { return a.first > b.first; });
        // --it;
        cout << k << " " << it->first << " - " << it->second << endl;
        li[it->first - 1] = k;
        ans += (k - it->first) * it->second;
        ar.erase(it);
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i)
        cout << li[i] << " ";
    return 0;
}