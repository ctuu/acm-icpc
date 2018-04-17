#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<long long, 35> dp;
    dp.fill(0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 35; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] += dp[j] * dp[i - j - 1];
    int n;
    while (cin >> n)
        cout << dp[n] << endl;
    return 0;
}