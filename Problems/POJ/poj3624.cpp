#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int wi[3405], vi[3405];
    for (int i = 0; i < n; ++i)
        cin >> wi[i] >> vi[i];
    int dp[12885] = {0};
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= wi[i]; --j)
            dp[j] = max(dp[j], dp[j - wi[i]] + vi[i]);
    cout << dp[m];
    return 0;
}