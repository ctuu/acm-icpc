#include <iostream>
#include <array>
using namespace std;

const int N = 3000 + 7;
const int INF = 0x3f3f3f3f;
array<int, N> s, c;
array<array<int, 3>, N> dp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (auto &i : dp)
        i.fill(INF);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (s[j] < s[i])
            {
                dp[i][1] = min(dp[i][1], c[j] + c[i]);
                dp[i][2] = min(dp[i][2], c[i] + dp[j][1]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; ++i)
        ans = min(ans, dp[i][2]);
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}