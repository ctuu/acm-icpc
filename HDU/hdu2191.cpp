#include <bits/stdc++.h>
#define N 105
#define M 105
#define P 25
#define H 205
#define C 25
using namespace std;
struct no
{
    int p, h;
    no() = default;
    no(int a, int b)
    {
        this->p = a;
        this->h = b;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<no> va;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            int p, h, c;
            int r = 1;
            cin >> p >> h >> c;
            while (c >= r && p * r <= n)
            {
                va.push_back(no(p * r, h * r));
                c -= r;
                r <<= 1;
            }
            while (c)
            {
                while (c < r)
                    r >>= 1;
                va.push_back(no(p * r, h * r));
                c -= r;
            }
        }
        // for (auto i: va)
        // cout << i.p << " " << i.h << endl;
        array<int, N> dp;
        dp.fill(0);
        int ct = va.size();
        for (int i = 0; i < ct; ++i)
            for (int j = n; j >= va[i].p; --j)
                dp[j] = max(dp[j], dp[j - va[i].p] + va[i].h);
        // for (int i = 0; i<= n; ++i)
        //     cout << dp[i] << " ";
        cout << dp[n] << endl;
    }
    return 0;
}