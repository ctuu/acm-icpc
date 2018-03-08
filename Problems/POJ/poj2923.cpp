#include <iostream>
#include <algorithm>
#include <vector>
#define C 100
#define W 100
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Scenario #" << i << ":\n";
        int n, c1, c2, fu[12];
        cin >> n >> c1 >> c2;
        if (c1 < c2)
            swap(c1, c2);
        for (int i = 0; i < n; ++i)
            cin >> fu[i];
        vector<int> va;
        for (int i = 1; i < 1 << n; ++i)
        {
            int sum = 0, dp[200] = {0};
            dp[0] = 1;
            for (int j = 0; j < n; ++j)
                if (i & (1 << j))
                {
                    sum += fu[j];
                    for (int k = c1 - fu[j]; k >= 0; --k)
                        if (dp[k])
                            dp[k + fu[j]] = 1;
                }
            for (int j = c1; j >= 0; --j)
                if (dp[j] && sum - j <= c2)
                {
                    va.push_back(i);
                    break;
                }
        }
        int dp[2000];
        for (int i = 0; i < 2000; ++i)
            dp[i] = INF;
        dp[0] = 0;
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j = (1 << n) - 1 - va[i]; j >= 0; --j)
                if (!(j & va[i]))
                    dp[j | va[i]] = min(dp[j | va[i]], dp[j] + 1);
        cout << dp[(1 << n) - 1] << "\n\n";
    }
    return 0;
}