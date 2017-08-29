#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    array<int, 30> ar;
    array<long long, 1002> dp;
    while (n--)
    {
        int v, d;
        cin >> v >> d;
        for (int i = 0; i < v; ++i)
            cin >> ar[i];
        sort(ar.begin(), ar.begin() + v);
        dp.fill(0);
        for (int i = 0; i < v; ++i)
        {
            for (int j = d; j > ar[i]; --j)
                dp[j] += dp[j - ar[i]];
            ++dp[ar[i]];
        }
        long long ans = 0;
        // for (int i = d; i > -1; --i)
        // {
        //     cout << dp[i] << " ";
        // }
        for (int i = d; i >= d - ar[0]; --i)
            ans += dp[i];
        cout << ans << endl;
    }
    return 0;
}