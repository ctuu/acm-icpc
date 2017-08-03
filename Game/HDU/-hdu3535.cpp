#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#define N 100
#define T 105
#define M 100
#define CI 100
#define GI 100
using namespace std;
struct no
{
    int ci, gi;
    no() = default;
    no(int a, int b)
    {
        this->ci = a;
        this->gi = b;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    while (cin >> n >> t)
    {
        int tm = t;
        vector<no> va;
        for (int i = 0; i < n; ++i)
        {
            int m, s;
            cin >> m >> s;
            for (int j = 0; j < m; ++j)
            {
                int ci, gi;
                int tt = t;
                int r = 1;
                if (s == 0)
                {
                    cin >> ci >> gi;
                    tm -= ci;
                    while (tt >= r)
                    {
                        va.push_back(no(ci * r, gi * r));
                        tt -= r;
                        r <<= 1;
                    }
                }
                else if (s == 1)
                {
                    cin >> ci >> gi;
                    va.push_back(no(ci, gi));
                }
                else
                {
                    cin >> ci >> gi;
                    while (tt >= r)
                    {
                        va.push_back(no(ci * r, gi * r));
                        tt -= r;
                        r <<= 1;
                    }
                }
            }
        }
        if (tm < 0)
        {
            cout << -1 << endl;
            continue;
        }
        array<int, T> dp;
        for (auto i: va)
        cout << " " << i.ci << " " << i.gi << endl;
        dp.fill(0);
        int ct = va.size();
            for (int i = 0; i < ct; ++i)
                for (int j = t; j >= va[i].ci; --j)
                    dp[j] = max(dp[j], dp[j - va[i].ci] + va[i].gi);
        // for (int i = 0; i < t; ++i)
        //     cout <<dp[i] << " ";
        cout << dp[t] << endl;
    }
    return 0;
}