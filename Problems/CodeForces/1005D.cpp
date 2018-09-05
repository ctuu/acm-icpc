#include <array>
#include <iostream>
#include <string>
using namespace std;
const int N = 2e5 + 7;
array<int, N> dp;
int main()
{
    dp.fill(0);

    string s;
    cin >> s;

    int si = s.size();
    dp[0] = ((s[0] - '0') % 3 == 0);
    int sum = (s[0] - '0') % 3;

    array<int, 5> nxt;
    nxt.fill(-1);
    nxt[sum] = 0;

    for (int i = 1; i < si; ++i)
    {
        int x = s[i] - '0';
        sum = (sum + x) % 3;
        dp[i] = dp[i - 1];
        if (sum == 0)
            dp[i] = max(dp[i], i);
        if (nxt[sum] != -1)
            dp[i] = max(dp[nxt[sum]] + 1, dp[i]);
        nxt[sum] = i;
    }
    cout << dp[si - 1] << endl;
    return 0;
}