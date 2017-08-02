#include <bits/stdc++.h>
#define N 105
#define MJ 105
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        double p;
        int n, sum = 0;
        cin >> p >> n;
        array<int, N> mj;
        array<double, N> pj;
        mj.fill(0);
        pj.fill(0);
        for (int i = 0; i < n; ++i)
        {
            cin >> mj[i] >> pj[i];
            pj[i] = 1 - pj[i];
            sum += mj[i];
        }
        array<double, N * MJ> dp;
        dp.fill(0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = sum; j >= mj[i]; --j)
                dp[j] = max(dp[j], dp[j - mj[i]] * pj[i]);
        for (int i = sum; i >= 0; --i)
            if (p > 1 - dp[i])
            {
                cout << i << endl;
                break;
            }
        }
    return 0;
}