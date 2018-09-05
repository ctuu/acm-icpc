#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d, ans = 2;
    array<int, 300> c;
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    sort(c.begin(), c.begin() + n);
    for (int i = 1; i < n; ++i)
    {
        if (c[i] - d >= c[i - 1] + d)
            ans++;
        if (c[i] - d > c[i - 1] + d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}