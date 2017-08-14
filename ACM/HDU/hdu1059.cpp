#include <bits/stdc++.h>
#define N 6
#define V 180005
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 0;
    array<int, N> mar;
    array<int, V> dp;
    while (++t)
    {
        vector<int> va;
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> mar[i];
            sum += mar[i] * (i + 1);
            int ts = mar[i] * (i + 1);
            int j = 1;
            while (ts >= j * (i + 1))
            {
                va.push_back(j * (i + 1));
                ts -= j * (i + 1);
                j <<= 1;
            }
            while (ts)
            {
                if (j > 1)
                    j >>= 1;
                if (ts >= j * (i + 1))
                {
                    va.push_back(j * (i + 1));
                    ts -= j * (i + 1);
                }
            }
        }
        if (!sum)
            return 0;
        if (sum & 1)
        {
            cout << "Collection #" << t << ":\n";
            cout << "Can't be divided.\n\n";
            continue;
        }
        dp.fill(0);
        int to = va.size();
        for (int i = 0; i < to; ++i)
            for (int j = sum / 2; j >= va[i]; --j)
                dp[j] = max(dp[j], dp[j - va[i]] + va[i]);
        cout << "Collection #" << t << ":\n";
        if (2 * dp[sum / 2] != sum)
            cout << "Can't be divided.\n\n";
        else
            cout << "Can be divided.\n\n";
        // cout << dp[sum/2] << endl;
    }
    return 0;
}