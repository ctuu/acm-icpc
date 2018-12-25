#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, s, sum = 0;
    cin >> n >> s;
    vector<long long> v;
    v.resize(n);
    for (auto &i : v)
    {
        cin >> i;
        sum += i;
    }
    if (sum < s)
    {
        cout << -1;
        return 0;
    }
    sort(v.begin(), v.end());
    long long ans = v[0];
    s -= sum - v[0] * n;
    while(s > 0)
    {
        s -= n;
        ans--;
    }
    cout << ans;
}