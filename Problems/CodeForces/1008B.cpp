#include <iostream>
#include <vector>
using namespace std;

using PII = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<PII> v;
    v.resize(n);
    for (auto &i : v)
        cin >> i.first >> i.second;

    v[0].second = max(v[0].second, v[0].first);

    for (int i = 1; i < n; ++i)
    {
        int mx = max(v[i].first, v[i].second);
        int mn = min(v[i].first, v[i].second);
        v[i].second = mx > v[i - 1].second ? mn : mx;
    }
    for (int i = 1; i < n; ++i)
    {
        if (v[i].second > v[i - 1].second)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
