#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
const int N = 120000 + 7;

array<int, N> a;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.begin() + n);

    array<long long, 33> b;
    b[0] = 1;
    for (int i = 1; i < 33; ++i)
        b[i] = b[i - 1] * 2;

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        bool t = 1;
        for (int j = 0; j < 32; ++j)
        {
            if (a[i] > b[j])
                continue;
            int rs = b[j] - a[i];
            int idx = lower_bound(a.begin(), a.begin() + n, rs) - a.begin();
            if (idx == i)
            {
                if (idx > 0 && a[idx - 1] == rs)
                    t = 0;
                else if (idx + 1 < n && a[idx + 1] == rs)
                    t = 0;
            }
            else if (a[idx] == rs)
                t = 0;
        }
        ans += t;
    }
    cout << ans << endl;
    return 0;
}
