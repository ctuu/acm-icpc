#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#define MN 5000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int va[6], dp[MN];
        for (int i = 0; i < 6; ++i)
            cin >> va[i];
        for (int i = 0; i <= MN; ++i)
            dp[i] = i;
        for (int i = 0; i < 6; ++i)
            for (int j = va[i]; j <= MN; ++j)
                dp[j] = min(dp[j], dp[j - va[i]] + 1);
        for (int i = 0; i < 6; ++i)
            for (int j = MN - va[i]; j >= 0; --j)
                dp[j] = min(dp[j], dp[j + va[i]] + 1);
        int ans = 0;
        double aver = 0;
        for (int i = 0; i <= 100; ++i)
        {
            aver += dp[i];
            ans = max(ans, dp[i]);
        }
        cout << fixed << setprecision(2) << aver / 100 << " " << ans << endl;
    }
    return 0;
}