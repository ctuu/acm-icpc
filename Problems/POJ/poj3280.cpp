#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int M = 3000;
int dp[M][M] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<char, int> cs;
    for (int i = 0; i < n; ++i)
    {
        char cur;
        int a, b;
        cin >> cur >> a >> b;
        cs[cur] = min(a, b);
    }

    for (int j = 1; j < m; ++j)
        for (int i = j - 1; i >= 0; --i)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1] + cs[s[j]], dp[i + 1][j] + cs[s[i]]);
        }

    cout << dp[0][m - 1] << endl;
    return 0;
}