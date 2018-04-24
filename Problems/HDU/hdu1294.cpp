#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int N = 43;
using LL = long long;
array<int, N + 7> ar;
LL p = 0, cnt;
array<LL, N + 7> dp;
LL com(LL n, LL m)
{
    m = min(m, n - m);
    LL i, s = 1;
    for (i = 1; i <= m; ++i)
        s = s * (n - i + 1) / i;
    return s;
}

void cf(int n, int mf)
{
    if (n <= 0)
    {
        LL tns = 1, k = 1;
        for (int i = 1; i < p; ++i)
        {
            if (ar[i] != ar[i - 1])
            {
                tns *= com(dp[ar[i - 1]] + k - 1, k);
                k = 0;
            }
            ++k;
        }
        tns *= com(dp[ar[p - 1]] + k - 1, k);
        dp[cnt] += tns;
        return;
    }
    for (int i = mf; i <= n; ++i)
    {
        ar[p] = i;
        ++p;
        cf(n - i, i);
        --p;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp.fill(0);
    dp[1] = dp[2] = 1;
    dp[3] = 2;
    cnt = 4;
    for (int i = 3; i < N; ++i)
    {
        cf(i, 1);
        cnt++;
    }
    int n;
    while (cin >> n)
        cout << dp[n] << endl;
    return 0;
}