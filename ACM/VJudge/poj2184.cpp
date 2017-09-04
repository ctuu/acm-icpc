#include <iostream>
#include <algorithm>
#include <vector>
#define SH 100000
#define INF 0x3f3f3f3f
using namespace std;
int dp[100005 + SH];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sos = 0, si[102], fi[102];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> si[i] >> fi[i];
        if (si[i] < 0 && fi[i] < 0)
        {
            --i;
            --n;
            continue;
        }
        if (si[i] > 0)
            sos += si[i];
    }
    for (int j = 0; j <= SH + sos; ++j)
        dp[j] = -INF;
    dp[SH] = 0;
    for (int i = 0; i < n; ++i)
        if (si[i] > 0)
            for (int j = sos + SH; j >= si[i]; --j)
                dp[j] = max(dp[j], dp[j - si[i]] + fi[i]);
        else
            for (int j = -si[i]; j <= sos + SH; ++j)
                dp[j + si[i]] = max(dp[j + si[i]], dp[j] + fi[i]);
    int ans = SH;
    for (int i = SH; i <= SH + sos; ++i)
        if (dp[i] >= 0)
            ans = max(ans, dp[i] + i);
    cout << ans - SH;
    return 0;
}