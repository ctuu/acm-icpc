#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5e5 + 7;
const int INF = 0x3f3f3f3f;
array<long long, N> a;
int n;

int main()
{
    cin >> n;
    a.fill(0);
    bool pos = 0, neg = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] >= 0 ? pos = 1 : neg = 1;
        if (n > 1)
            a[i] = abs(a[i]);
    }
    long long ans = 0;
    if (pos && neg)
        for (int i = 0; i < n; ++i)
            ans += a[i];

    else if (n > 1)
    {
        int x = 0, y = 1;
        if (a[x] > a[y])
            swap(x, y);
        int minx = a[x];
        for (int i = 1; i < n - 1; ++i)
        {
            int p = i, q = i + 1;
            if (a[p] > a[q])
                swap(p, q);
            int tmp = a[p];
            if (tmp < minx)
            {
                minx = tmp;
                x = p, y = q;
            }
        }
        for (int i = 0; i < n; ++i)
            if (i != x && i != y)
                ans += a[i];
        ans += abs(a[x] - a[y]);
    }

    else
        ans = a[0];

    cout << ans << endl;
    return 0;
}