#include <bits/stdc++.h>
#define N 505
#define M 5005
using namespace std;

struct no
{
    int pi, qi, vi;
    no() = default;
    no(int a, int b, int c)
    {
        this->pi = a;
        this->qi = b;
        this->vi = c;
    }
};
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int n, m;
    array<no, N> mer;
    array<int, M> dp;
    while (cin >> n >> m)
    {
        mer.fill(no(0, 0, 0));
        dp.fill(0);
        for (int i = 0; i < n; ++i)
            cin >> mer[i].pi >> mer[i].qi >> mer[i].vi;
        sort(mer.begin(), mer.begin() + n, [](no a, no b) { return a.qi + b.pi < b.qi + a.pi; });
        for (int i = 0; i < n; ++i)
            for (int j = m; j >= mer[i].qi; --j)
                dp[j] = max(dp[j], dp[j - mer[i].pi] + mer[i].vi);
        cout << dp[m] << endl;
    }
    return 0;
}