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
        int v, d;
        cin >> v >> d;
        for (int i = 0; i < v; ++i)
            cin >> ar[i];
        sort(ar, ar + v);
        long long dp[1002];
        int sum = 0;
        long long ans = 0;
        for (int i = 0; i < v; ++i) // 剩余物品中最小的
        {
            for (int j = 0; j < 1002; ++j)
                dp[j] = 0;
            dp[sum] = 1;
            for (int j = i + 1; j < v; ++j)
                for (int k = d; k >= ar[j] + sum; --k)
                    dp[k] += dp[k - ar[j]];
            for (int j = d; j > max(d - ar[i], 0); --j)
                if (j >= sum)
                    ans += dp[j];
            sum += ar[i];
        }
        ans += (d > sum);
        cout << t << " " << ans << endl;
    }
    return 0;
}