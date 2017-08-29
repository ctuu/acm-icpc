#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ar[30];
    for (int t = 1; t <= n; ++t)
    {
        int v, d, sum = 0, f[1005];
        cin >> v >> d;
        for (int i = 0; i < v; ++i)
        {
            cin >> ar[i];
            sum += ar[i];
        }
        sort(ar, ar + v);
        long long ans = 0;
        for (int i = 0; i < 1005; ++i)
            f[i] = 0;
        f[0] = 1;
        ans += (d > sum);
        for (int i = v - 1; i > -1; --i)
        {
            sum -= ar[i];
            for (int j = d - sum; j >= max(d - sum - ar[i] + 1, 0); --j)
                ans += f[j];
            for (int j = d; j >= max(ar[i], 0); --j)
                f[j] += f[j - ar[i]];
        }
        ans -= (d < ar[0]);
        cout << t << " " << ans << endl;
    }
    return 0;
}