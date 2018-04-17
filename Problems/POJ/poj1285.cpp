#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t, T = 1;
    while (cin >> n >> m && n && m)
    {
        unsigned long long dp[53] = {0}, lb[53] = {0};
        for (int i = 0; i < n; ++i)
        {
            cin >> t;
            lb[t]++;
        }
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = n; j >= 0; --j)
                for (int k = 1; k <= lb[i]; ++k)
                    if (j - k >= 0)
                        dp[j] += dp[j - k];
        cout << "Case " << T++ <<":"<<endl;
        for (int i = 0; i < m; ++i)
        {
            cin >> t;
            cout << dp[t] << endl;
        }
    }
    return 0;
}