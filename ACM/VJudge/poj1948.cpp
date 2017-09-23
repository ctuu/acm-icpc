#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int calc(int x, int y, int z)
{
    double p = (x + y + z) / 2.0;
    return (int)(sqrt(p * (p - x) * (p - y) * (p - z)) * 100);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int va[42];
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> va[i];
        sum += va[i];
    }
    int m = sum / 2 - ((sum & 1) == 0);
    bool dp[920][920] = {0};
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= 0; --j)
            for (int k = j; k >= 0; --k)
                if (dp[j][k])
                    dp[j + va[i]][k] = dp[j][k + va[i]] = 1;
    int ans = -1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= i; ++j)
            if (dp[i][j])
                ans = max(ans, calc(i, j, sum - i - j));
    cout << ans << endl;
    return 0;
}