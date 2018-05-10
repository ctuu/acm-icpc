#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 7;
const int INF = 0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ar[N], dp[N];
    int n;
    while(cin >> n)
    {
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
            cin >> ar[i];
        for(int i = 0; i < n; ++i)
        {
            int c = ar[i];
            *lower_bound(dp, dp + n, c) = c;
        }
        int ans = 0;
        while(dp[ans+1] != INF)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
