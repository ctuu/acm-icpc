#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int vi[10002];
    for (int i = 0; i < n; ++i)
        cin >> vi[i];
    bool dp[2][103] = {0};
    dp[1][abs(vi[0]) % k] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 103; ++j)
        {
            dp[0][j] = dp[1][j] & 1;
            dp[1][j] &= 0;
        }
        for (int j = k; j >= 0; --j)
            if (dp[0][j])
            {
                dp[1][(j + abs(vi[i]) % k) % k] = 1;
                dp[1][abs(j - abs(vi[i]) % k) % k] = 1;
            }
    }
    if (dp[1][0])
        cout << "Divisible";
    else
        cout << "Not divisible";
    return 0;
}