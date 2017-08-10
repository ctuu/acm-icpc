#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#define M 5005
#define S 5005
using namespace std;
array<array<int, S>, S> dp;
array<array<int, S>, S> co;
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
        for (auto &i : dp)
            i.fill(0);
        for (auto &i : co)
            i.fill(0);
        int ct = s.size();
        int ans = 0;
        for (int i = 0; i < ct; ++i)
        {
            int ti = i, j = ct - 1;
            for (int k = j; k > co[i][j] + ti; --k)
            {
                if (dp[i][j] + abs(s[ti + co[i][j]] - s[k]) <= m)
                {
                    dp[i][j] += abs(s[ti + co[i][j]] - s[k]);
                    ++co[i][j];
                    ans = max (ans, co[i][j]);
                }
                else
                {
                    dp[i][j - 1] = dp[i][j] - abs(s[ti] - s[j]);
                    co[i][j - 1] = co[i][j] - 1;
                    --j;
                    ++ti;
                    ++k;
                }
            }
        }
        
        // for (int i = 0; i < ct; ++i)
        // {
        //     for (int j = 0; j < ct; ++j)
        //     {
        //         cout << co[i][j];
        //         ans = max(ans, co[i][j]);
        //     }
        // }
        cout << ans << endl;
    }
    return 0;
}