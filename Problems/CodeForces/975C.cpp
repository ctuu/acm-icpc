#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
using LL = long long;
array<LL, 200004> a, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    a.fill(0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }
    for (int i = 0; i < q; ++i)
        cin >> k[i];
    LL sm = 0;
    for (int i = 0; i < q; ++i)
    {
        sm += k[i];
        if (sm >= a[n - 1])
        {
            sm = 0;
            cout << n << endl;
            continue;
        }
        int j = lower_bound(a.begin(), a.begin() + n, sm) - a.begin();
        if(a[j] == sm)
            j++;
        cout << n - j << endl;
    }
    return 0;
}
