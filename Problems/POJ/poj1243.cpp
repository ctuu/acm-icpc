#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dp[33][33];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < 33; ++i)
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
                dp[i][j] = i;
            else if (j == i)
                dp[i][j] = pow(2, i) - 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + 1 + dp[i - 1][j];
        }
    int t = 0, g, l;
    while (cin >> g >> l)
    {
        if (!(g | l))
            return 0;
        l = g < l ? g : l;
        cout << "Case " << ++t << ": " << dp[g][l] << endl;
    }
    return 0;
}