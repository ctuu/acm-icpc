#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
using namespace std;
const int N = 2000;
array<array<int, N>, N> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (cin >> s)
    {
        for (auto &i : s)
            if (isalpha(i))
                i = tolower(i);
        int si = s.size();
        for (auto &i : dp)
            i.fill(0);
        for (int i = si - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < si; ++j)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        cout <<dp[0][si - 1] << endl;
    }
    return 0;
}
