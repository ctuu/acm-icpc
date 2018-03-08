#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    array<double, 50004> ar;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> ar[i];
        if (n - k <= 1)
        {
            cout << "0" << endl;
            continue;
        }
        sort(ar.begin(), ar.begin() + n);
        double cen = 0, ss = 0;
        for (int i = 0; i < n - k; ++i)
        {
            cen += ar[i];
            ss += ar[i] * ar[i];
        }
        double ans = ss - cen * cen / (double)(n - k);
        for (int i = n - k; i < n; ++i)
        {
            cen = cen - ar[i - (n - k)] + ar[i];
            ss = ss - ar[i - (n - k)] * ar[i - (n - k)] + ar[i] * ar[i];
            ans = min(ans, ss - cen * cen / (double)(n - k));
        }
        cout << fixed << setprecision(9) << ans << endl;
    }
    return 0;
}