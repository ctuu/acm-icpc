#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5007;
pair<int, int> ar[N];
int dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = cin >> T ? T : 0;
    while (T--)
    {
        int n = cin >> n ? n : 0;
        for(int i = 0; i < n; ++i)
            cin >> ar[i].first >> ar[i].second;
        
        sort(ar, ar + n);
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; ++i)
            *lower_bound(dp, dp + n, ar[i].second, greater<int>()) = ar[i].second;
        cout << lower_bound(dp, dp + n, -1, greater<int>()) - dp << endl;
    }
    return 0;
}
