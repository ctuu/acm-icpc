#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#define M 5005
#define S 5005
using namespace std;
array<int, S> dp;
array<int, S> co;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        string s;
        cin >> s;
        int ct = s.size();
        int ans = 0;
        for (int i = 0; i < ct; ++i)
        {
            int ti = i, j = ct - 1;
            co.fill(0);
            dp.fill(0);
            for (int k = j; k > ti + co[j]; --k)
            {
                if (dp[j] + abs(s[ti + co[j]] - s[k]) <= m)
                {
                    dp[j] += abs(s[ti + co[j]] - s[k]);
                    ++co[j];
                    ans = max(ans, co[j]);
                }
                else
                {
                    dp[j - 1] = dp[j] - abs(s[ti] - s[j]);
                    co[j - 1] = co[j] - 1;
                    --j;
                    ++ti;
                    ++k;
                }
            }
        }

        // for (int i = ct - 1; i > -1; --i)
        // {
        //     int ti = i, j = 0;
        //     co.fill(0);
        //     dp.fill(0);
        //     for (int k = j; k < ti - co[j]; ++k)
        //     {
        //         if (dp[j] + abs(s[ti - co[j]] - s[k]) <= m)
        //         {
        //             dp[j] += abs(s[ti - co[j]] - s[k]);
        //             ++co[j];
        //             ans = max(ans, co[j]);
        //         }
        //         else
        //         {
        //             dp[j + 1] = dp[j] - abs(s[ti] - s[j]);
        //             co[j + 1] = co[j] - 1;
        //             ++j;
        //             --ti;
        //             --k;
        //         }
        //     }
        // }
        cout << ans << endl;
    }
    return 0;
}