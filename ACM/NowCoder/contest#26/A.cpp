#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using ULL = unsigned long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ULL n, t, ans = 0;
    cin >> n >> t;
    for (ULL i = 0; i < n; ++i)
    {
        ULL x, y, z;
        cin >> x >> y >> z;
        ULL beg = 1, end = 2000000002, mid;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (mid * (x + y) + mid * (mid - 1) * z / 2 >= t)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        ULL k = mid * (x + y) + mid * (mid - 1) * z / 2;
        if (k > t)
            --mid;
        ULL tmp = mid * (x + y) + mid * (mid - 1) / 2 * z;
        ans += (t > x + tmp) ? t - x - tmp : 0;
        ans += mid * y + mid * (mid - 1) * z / 2;
    }
    cout << ans << endl;
    return 0;
}