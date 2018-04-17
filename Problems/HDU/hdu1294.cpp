#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<int, 43> dp;
    dp.fill(0);
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i < 43; ++i)
    {
        for(int j = i - 1; j >= i - j + 1; --j)
            dp[i] += dp[j] + dp[i - j + 1];
        if(i%2 == 0)
            dp[i]++;
    }
    cout << dp[4] << endl;
    cout << dp[7] << endl;
    return 0;
}