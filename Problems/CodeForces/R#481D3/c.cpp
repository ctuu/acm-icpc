#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 7;
const int M = 2e5 + 7;
using LL = long long;
array<LL, N> a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    LL b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> b;
        int k = lower_bound(a.begin(), a.begin() + n, b) - a.begin();
        cout << k << " " << b - a[k - 1] << endl;
    }
    return 0;
}