#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 13;
const int M = 13;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // array<array<int, N>, M> dp;
    int dp[M][N];
    memset(dp, 0, sizeof(dp));
    // dp[0].fill(1);
    for(int i = 0; i < N; ++i)
        dp[0][i] = 1;
    for (int i = 1; i < M; ++i)
        for (int j = 1; j < N; ++j)
        {
            dp[i][j] = dp[i][j-1];
            if (i >= j)
                dp[i][j] += dp[i-j][j];
        }
    int t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
    return 0;
}