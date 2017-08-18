#include <iostream>
#include <algorithm>
#include <vector>
#define VN 35
#define DN 1005
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int t = 1; t <= n; ++t)
    {
        cout << t << " ";
        int v, d, va[VN];
        cin >> v >> d;
        for (int i = 0; i < v; ++i)
            cin >> va[i];
        unsigned int dp[DN] = {0}, way[DN] = {0};
        way[0] = 1;
        for (int i = 0; i < v; ++i)
            for (int j = d; j >= va[i]; --j)
                if (dp[j - va[i]] + va[i] > dp[j])
                {
                    dp[j] = dp[j - va[i]] + va[i];
                    way[j] = way[j - va[i]];
                }
                else if (dp[j - va[i]] + va[i] == dp[j])
                    way[j] += way[j - va[i]];
        cout << way[d] << endl;
    }
    return 0;
}