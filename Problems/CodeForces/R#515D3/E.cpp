#include <iostream>
#include <algorithm>
#include <array>
#include <string>
using namespace std;
const int N = 2e5 + 7;
const int MOD = 998244353;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c = 0;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (auto i : b)
        c += (i == '1');
    long long ans = 0, d = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
            ans = (ans + d * c) % MOD;
        d = (d << 1) % MOD;
        c -= (c && b[i] == '1');
    }
    cout << ans << endl;
    return 0;
}