#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v;
    v.resize(n);
    long long ans = 0, mx = 0;
    for (auto &i : v)
    {
        cin >> i;
        ans += i;
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] == v[i + 1])
            v[i + 1] = max(v[i + 1] - 1, 1);
        else if (v[i] < v[i + 1])
            v[i + 1] = max(v[i] - 1, 1);
    }
    v.push_back(0);
    for (int i = 0; i < n; ++i)
        mx += max(v[i] - v[i + 1], 1);
    cout << ans - mx << endl;
    return 0;
}