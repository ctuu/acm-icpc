#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int d, v, l, r;
        cin >> d >> v >> l >> r;
        long long ans = d / v;
        ans += (l-1) / v;
        ans -= r / v;
        cout << ans << endl;
    }
    return 0;
}