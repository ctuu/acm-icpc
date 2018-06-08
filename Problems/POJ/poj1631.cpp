#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 400007;
int dp[N], c[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        memset(dp, INF, sizeof(dp));
        for(int i = 0; i < n; ++i)
            cin >> c[i];
        for(int i = 0; i < n; ++i)
            *lower_bound(dp, dp + n, c[i]) = c[i];
        int ans = 0;
        while(dp[ans] != INF)
            ++ans;
        cout << ans << endl;
    }
    return 0;
}
