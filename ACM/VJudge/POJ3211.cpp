#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<string, int> ta;
    int n, m;
    while (cin >> n >> m && n && m)
    {
        for (int i = 0; i < n; ++i)
        {
            string tmp;
            cin >> tmp;
            ta[tmp] = i;
        }
        vector<int> va[11];
        int su[11] = {0};
        for (int i = 0; i < m; ++i)
        {
            int t;
            string tmp;
            cin >> t >> tmp;
            va[ta[tmp]].push_back(t);
            su[ta[tmp]] += t;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int dp[101000] = {0};
            int ct = va[i].size();
            for (int j = 0; j < ct; ++j)
                for (int k = su[i]; k >= va[i][j]; --k)
                    dp[k] = max(dp[k], dp[k - va[i][j]] + va[i][j]);
            ans += su[i] - dp[su[i] / 2];
        }
        cout << ans << endl;
    }
    return 0;
}