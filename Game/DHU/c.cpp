#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main()
{
    array<int, 100002> nu;
    long long n, k;
    while (cin >> n >> k)
    {
        nu.fill(0);
        nu[0] = 1;
        long long sum = 0;
        for (int i = 1; i < k; ++i)
        {
            nu[i] = 2 * nu[i - 1] % MOD;
        }
        sum = (2 * nu[k - 1] - 1) % MOD;
        for (int i = k; i < n; ++i)
        {
            nu[i] = sum;
            sum = (2 * sum) % MOD - nu[i - k] % MOD;
            if (sum < 0)
                sum += MOD;
            else
                sum %= MOD;
        }
        cout << nu[n - 1] << endl;
    }
    return 0;
}