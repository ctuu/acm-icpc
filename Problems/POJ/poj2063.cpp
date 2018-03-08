#include <iostream>
#include <algorithm>
#include <vector>
#define MC 50005
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int y, d;
        cin >> n >> y >> d;
        pair<int, int> va[15];
        for (int i = 0; i < d; ++i)
        {
            cin >> va[i].first >> va[i].second;
            va[i].first /= 1000;
        }
        while (y--)
        {
            int tn = n / 1000;
            int dp[MC] = {0};
            for (int i = 0; i < d; ++i)
                for (int j = va[i].first; j <= tn; ++j)
                    dp[j] = max(dp[j], dp[j - va[i].first] + va[i].second);
            n += dp[tn];
        }
        cout << n << endl;
    }
    return 0;
}