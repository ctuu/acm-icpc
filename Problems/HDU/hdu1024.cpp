#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1000003;
array<int, 1000003> a, dp, lm;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m)
    {
        for(int i = 0; i < m; ++i)
            cin >> a[i];
        int mmx = 0;
        for(int i = 0; i < n; ++i)
        {
            mmx = -INF;
            for(int j = i; j <= m; ++j)
            {
                dp[j] = max(dp[j - 1] + a[j], lm[j-1] + a[j]);
                lm[j-1] = mmx;
                mmx = max(mmx, dp[j]);
            }
        }
        cout << mmx << endl;
    }
    return 0;
}