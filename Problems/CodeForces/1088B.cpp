#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<long long> v;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    long long lst = 0;
    sort(v.begin(), v.end());
    int idx = 0;
    while (k--)
    {

        while (idx < n && !v[idx])
            ++idx;
        while (idx < n)
        {
            v[idx] = max(0ll, v[idx] - lst);
            if (v[idx] > 0)
                break;
            ++idx;
        }
        if (idx >= n)
        {
            cout << '0' << '\n';
            continue;
        }
        cout << v[idx] << '\n';
        lst += v[idx];
        v[idx] = 0;
    }
    return 0;
}