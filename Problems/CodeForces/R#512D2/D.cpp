#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL n, m, k, on, om;
    cin >> n >> m >> k;
    on = n, om = m;
    LL gn = __gcd(n, k);
    LL gm = __gcd(m, k);
    while (gn != 1 || gm != 1)
    {
        if (gn > gm)
            n /= gn;
        else
            m /= gm;
        k /= max(gn, gm);
        gn = __gcd(n, k);
        gm = __gcd(m, k);
    }
    if (k > 2)
    {
        cout << "NO" << endl;
        return 0;
      }
    LL x1 = n, y3 = m;
    if (k == 1)
    {
        if (n * 2 <= on)
            x1 *= 2;
        else if (m * 2 <= om)
            y3 *= 2;
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << x1 << ' ' << 0 << endl;
    cout << 0 << ' ' << 0 << endl;
    cout << 0 << ' ' << y3 << endl;
    return 0;
}