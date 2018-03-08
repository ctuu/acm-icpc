#include <iostream>
#include <algorithm>
#include <vector>
#define PC 50005
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int va[PC] = {0};
        int pc;
        cin >> pc;
        for (int i = 1; i <= pc; ++i)
        {
            cin >> va[i];
            va[i] += va[i - 1];
        }
        int k;
        cin >> k;
        int dp[PC][4] = {0};
        for (int i = 1; i <= pc; ++i)
            for (int j = 1; j <= 3; ++j)
            {
                if (i < j * k)
                    dp[i][j] = va[i];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - k][j - 1] + va[i] - va[i - k]);
            }
        cout << dp[pc][3] << endl;
    }
    return 0;
}