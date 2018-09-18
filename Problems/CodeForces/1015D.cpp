#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

using LL = long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL n, k, s;
    cin >> n >> k >> s;
    if ((n - 1) * k < s || k > s)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    LL idx = 1;
    while (s > (n - 1) && s - n + 1 >= k)
    {
        idx = idx == 1 ? n : 1;
        cout << idx << " ";
        k--;
        s -= n - 1;
    }
    LL pr = s / k;
    pr += (s % k > (n - 1));
    LL lpr = s - (k - 1) * pr;
    if (lpr > pr)
    {
        k--;
        s -= lpr;
        idx = idx == 1 ? 1 + lpr : n - lpr;
        cout << idx;
        while (k > 0)
        {
            idx = idx + pr > n ? idx - pr : idx + pr;
            cout << " " << idx;
            k--;
        }
    }
    else
    {
        while (k > 1)
        {
            idx = idx + pr > n ? idx - pr : idx + pr;
            cout << idx << " ";
            k--;
        }
        idx = idx + lpr > n ? idx - lpr : idx + lpr;
        cout << idx;
    }
    return 0;
}
