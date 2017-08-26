#include <iostream>
#include <algorithm>
#include <vector>
#define VN 35
#define DN 1005
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int t = 1; t <= n; ++t)
    {
        cout << t << " ";
        int v, d, va[VN];
        cin >> v >> d;
        int c = d;
        for (int i = 0; i < v; ++i)
        {
            cin >> va[i];
            c -= va[i];
        }
        unsigned int dp[DN] = {0};
        dp[0] = 1;
        sort(va, va + v);
        int ans = (c >= 0);
        if (va[0] <= d)
            for (int i = v - 1; i > -1; --i)
            {
                if ((c += va[i]) >= 0)
                    for (int j = max(0, c - va[i] + 1); j <= c; ++j)
                        ans += dp[j];
                for (int j = d; j >= va[i]; --j)
                    dp[j] += dp[j - va[i]];
            }
        cout << ans << endl;
    }
    return 0;
}