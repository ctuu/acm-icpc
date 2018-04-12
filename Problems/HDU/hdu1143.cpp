#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<array<int, 33>, 3> dp;
    for(auto &i: dp)
        i.fill(0);
    dp[0][0] = dp[1][1] = dp[2][0] = 1;
    for(int  i = 2; i < 33; ++i)
    {
        dp[0][i] = dp[0][i-2] + dp[1][i-1] + dp[2][i-2];
        dp[1][i] = dp[2][i-1];
        dp[2][i] = dp[0][i] + dp[1][i-1];
    }
    int n;
    while(cin >> n && n != -1)
        cout << dp[0][n] << endl;
    return 0;
}